/*******************************************************************************
 * Copyright (C) 2013-2015 Olaf Lessenich.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301  USA
 *
 * Contributors:
 *     Olaf Lessenich <lessenic@fim.uni-passau.de>
 *******************************************************************************/
package de.fosd.jdime.matcher.unordered;

import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

import de.fosd.jdime.common.Artifact;
import de.fosd.jdime.common.MergeContext;
import de.fosd.jdime.matcher.Matcher;
import de.fosd.jdime.matcher.Matching;

/**
 * @author Olaf Lessenich
 *
 * @param <T>
 *            type of artifact
 */
public class UniqueLabelMatcher<T extends Artifact<T>> extends
		UnorderedMatcher<T> {

	/**
	 * @param matcher
	 *            matcher
	 */
	public UniqueLabelMatcher(final Matcher<T> matcher) {
		super(matcher);
	}

	/**
	 * TODO: this needs explanation, I'll fix it soon.
	 */
	@Override
	public final Matching<T> match(final MergeContext context, final T left, final T right, int lookAhead) {
		int rootMatching = left.matches(right) ? 1 : 0;

		if (rootMatching == 0) {
			if (lookAhead == 0) {
				// roots contain distinct symbols and we cannot use the look-ahead feature
				// therefore, we ignore the rest of the subtrees and return early to save time
				// therefore, we ignore the rest of the subtrees and return early to save time
				return new Matching<>(left, right, rootMatching);
			} else {
				lookAhead = lookAhead - 1;
			}
		} else if (context.isLookAhead()) {
			lookAhead = context.getLookAhead();
		}

		if (left.getNumChildren() == 0 || right.getNumChildren() == 0) {
			return new Matching<>(left, right, rootMatching);
		}

		List<Matching<T>> childrenMatchings = new LinkedList<>();
		List<T> leftChildren = left.getChildren();
		List<T> rightChildren = right.getChildren();

		Collections.sort(leftChildren);
		Collections.sort(rightChildren);

		Iterator<T> leftIt = leftChildren.iterator();
		Iterator<T> rightIt = rightChildren.iterator();
		T leftChild = leftIt.next();
		T rightChild = rightIt.next();
		int sum = 0;

		boolean done = false;
		while (!done) {
			int c = leftChild.compareTo(rightChild);
			if (c < 0) {
				if (leftIt.hasNext()) {
					leftChild = leftIt.next();
				} else {
					done = true;
				}
			} else if (c > 0) {
				if (rightIt.hasNext()) {
					rightChild = rightIt.next();
				} else {
					done = true;
				}
			} else if (c == 0) {
				// matching
				Matching<T> childMatching = matcher.match(context, leftChild, rightChild, lookAhead);

				// Matching<T> childMatching
				// = new Matching<T>(leftChild, rightChild, 1);
				childrenMatchings.add(childMatching);
				sum += childMatching.getScore();
				if (leftIt.hasNext() && rightIt.hasNext()) {
					leftChild = leftIt.next();
					rightChild = rightIt.next();
				} else {
					done = true;
				}

			}
		}

		Matching<T> matching = new Matching<>(left, right, sum + rootMatching);
		matching.setChildren(childrenMatchings);
		return matching;
	}
}
