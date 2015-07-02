package de.fosd.jdime.matcher;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.Set;
import java.util.function.BiFunction;
import java.util.stream.Collectors;

import de.fosd.jdime.common.Artifact;
import de.fosd.jdime.common.UnorderedTuple;

/**
 * A <code>Set</code> of <code>Matching</code>s. Adds methods to retrieve specific elements of the <code>Set</code>
 * by their matched <code>Artifact</code>s.
 *
 * @param <T>
 * 		the type of the <code>Artifact</code>s
 */
public class Matchings<T extends Artifact<T>> extends HashSet<Matching<T>> {

	/**
	 * Creates a new <code>Matchings</code> instance containing a single <code>Matching</code> that matches
	 * <code>left</code> and <code>right</code> with the given <code>score</code>.
	 *
	 * @param left
	 * 		the left <code>Artifact</code>
	 * @param right
	 * 		the right <code>Artifact</code>
	 * @param score
	 * 		the score of the matching
	 * @param <T>
	 * 		the type of the <code>Artifact</code>s
	 * @return the new <code>Matchings</code> instance
	 */
	public static <T extends Artifact<T>> Matchings<T> of(T left, T right, int score) {
		Matchings<T> result = new Matchings<>();
		result.add(new Matching<>(left, right, score));

		return result;
	}

	/**
	 * Optionally returns the <code>Matching</code> matching the given <code>Artifact</code>s if there is such a
	 * <code>Matching</code> in the <code>Set</code>. If <code>left</code> is a choice node then the first
	 * matching of a variant of <code>left</code> and <code>right</code> is returned.
	 *
	 * @param artifacts
	 * 		the <code>Artifact</code>s whose <code>Matching</code> is to be returned
	 * @return optionally the <code>Matching</code> matching the given <code>artifacts</code>
	 */
	public Optional<Matching<T>> get(UnorderedTuple<T, T> artifacts) {
		T left = artifacts.getX();
		T right = artifacts.getY();

		if (left.isChoice()) {

			for (T variant : left.getVariants().values()) {
				Optional<Matching<T>> m = get(variant, right);

				if (m.isPresent()) {
					Matching<T> matching = m.get();
					Matching<T> variantMatching = new Matching<>(left, right, matching.getScore());
					variantMatching.setAlgorithm(matching.getAlgorithm());

					return Optional.of(variantMatching);
				}
			}

			return Optional.empty();
		}

		return stream().filter(matching -> matching.getMatchedArtifacts().equals(artifacts)).findFirst();
	}

	/**
	 * Optionally returns the <code>Matching</code> matching the given <code>Artifact</code>s if there is such a
	 * <code>Matching</code> in the <code>Set</code>. If <code>left</code> is a choice node then the first
	 * matching of a variant of <code>left</code> and <code>right</code> is returned.
	 *
	 * @param left
	 * 		the left <code>Artifact</code> of the <code>Matching</code>
	 * @param right
	 * 		the right <code>Artifact</code> of the <code>Matching</code>
	 * @return optionally the <code>Matching</code> matching the given <code>artifacts</code>
	 */
	public Optional<Matching<T>> get(T left, T right) {
		return get(UnorderedTuple.of(left, right));
	}

	/**
	 * Optionally returns the score of the <code>Matching</code> matching the given <code>Artifact</code>s if there
	 * is such a <code>Matching</code> in the <code>Set</code>.
	 *
	 * @param artifacts
	 * 		the <code>Artifact</code>s whose <code>Matching</code>s score is to be returned
	 * @return optionally the matching score for the given <code>artifacts</code>
	 */
	public Optional<Integer> getScore(UnorderedTuple<T, T> artifacts) {
		Optional<Matching<T>> matching = get(artifacts);

		if (matching.isPresent()) {
			return Optional.of(matching.get().getScore());
		} else {
			return Optional.empty();
		}
	}

	/**
	 * Optionally returns the score of the <code>Matching</code> matching the given <code>Artifact</code>s if there
	 * is such a <code>Matching</code> in the <code>Set</code>.
	 *
	 * @param left
	 * 		the left <code>Artifact</code> of the <code>Matching</code>
	 * @param right
	 * 		the right <code>Artifact</code> of the <code>Matching</code>
	 * @return optionally the matching score for the given <code>artifacts</code>
	 */
	public Optional<Integer> getScore(T left, T right) {
		return getScore(UnorderedTuple.of(left, right));
	}

	/**
	 * Adds all <code>Matchings</code> contained in the given collection.
	 *
	 * @param matchings
	 * 		the <code>Matchings</code> to add
	 */
	public void addAllMatchings(Collection<? extends Matchings<T>> matchings) {
		for (Matchings<T> matching : matchings) {
			addAll(matching);
		}
	}

	/**
	 * Returns a <code>Matchings</code> instance containing for every matched Artifact in this <code>Matchings</code>
	 * the <code>Matching</code> containing it that has the highest score.
	 *
	 * @return a new <code>Matchings</code> instance
	 */
	public Matchings<T> optimized() {
		Map<Artifact<T>, List<Matching<T>>> matchings = new HashMap<>();

		forEach(matching -> {
			UnorderedTuple<T, T> artifacts = matching.getMatchedArtifacts();
			BiFunction<Artifact<T>, List<Matching<T>>, List<Matching<T>>> adder = (artifact, list) -> {
				if (list == null) {
					list = new ArrayList<>();
				}
				list.add(matching);

				return list;
			};

			matchings.compute(artifacts.getX(), adder);
			matchings.compute(artifacts.getY(), adder);
		});

		Set<Matching<T>> filtered = matchings.entrySet()
											 .stream()
											 .map(entry -> Collections.max(entry.getValue(), (o1, o2) -> o1.getScore() - o2.getScore()))
											 .collect(Collectors.toSet());

		Matchings<T> res = new Matchings<>();
		res.addAll(filtered);

		return res;
	}
}
