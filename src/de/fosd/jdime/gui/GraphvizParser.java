package de.fosd.jdime.gui;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import javafx.concurrent.Task;
import javafx.scene.control.TreeItem;

/**
 * A <code>Task</code> parsing a <code>String</code> produced by JDime using '-mode dumpgraph' into a <code>List</code>
 * of <code>TreeItem</code>s representing root nodes for trees of AST nodes.
 */
class GraphvizParser extends Task<List<TreeItem<TreeDumpNode>>> {

	private static final Pattern digraphStart = Pattern.compile(".*digraph ast \\{");
	private static final Pattern digraphEnd = Pattern.compile("\\}");
	private static final Pattern node = Pattern.compile("\"?([^\"]+)\"?\\[label=\"\\([0-9]+\\) (.+)\"(, fillcolor = (.+),)?.*\\];");
	private static final Pattern connection = Pattern.compile("\"?([^\"]+)\"?->\"?([^\"]+)\"?;");

	private List<String> text;

	/**
	 * Constructs a new <code>GraphvizParser</code> parsing the given lines when {@link #call()} is
	 * called.
	 *
	 * @param text
	 * 		the lines to parse
	 */
	public GraphvizParser(List<String> text) {
		this.text = text;
	}

	@Override
	protected List<TreeItem<TreeDumpNode>> call() {
		List<TreeItem<TreeDumpNode>> roots = new ArrayList<>();
		Map<String, TreeItem<TreeDumpNode>> nodes = new HashMap<>();
		List<TreeItem<TreeDumpNode>> noParent = new ArrayList<>();

		for (String line : text) {

			if (digraphStart.matcher(line).matches()) {
				nodes.clear();
				noParent.clear();
			} else if (digraphEnd.matcher(line).matches()) {
				if (noParent.size() == 1) {
					roots.add(noParent.get(0));
				} else {
					System.err.println("Connections in the Graphviz format are wrong, there are " + noParent.size() +
							" nodes without a parent node.");
				}
			} else {
				Matcher matcher;

				if ((matcher = node.matcher(line)).matches()) {
					String id = matcher.group(1);
					String label = matcher.group(2);
					String color = matcher.group(4);
					TreeDumpNode node = new TreeDumpNode(id, label);
					TreeItem<TreeDumpNode> item = new TreeItem<>(node);

					if (color != null) {
						node.setFillColor(color);
					}

					nodes.put(id, item);
					noParent.add(item);
				} else if ((matcher = connection.matcher(line)).matches()) {
					String leftId = matcher.group(1);
					String rightId = matcher.group(2);
					TreeItem<TreeDumpNode> left = nodes.get(leftId);
					TreeItem<TreeDumpNode> right = nodes.get(rightId);

					left.getChildren().add(right);
					noParent.remove(right);
				}
			}
		}

		return roots;
	}
}
