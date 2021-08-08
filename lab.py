import networkx as nx
import matplotlib.pyplot as plt

import json



G = nx.DiGraph()

nomes = [(16, 15), (0,4), (2,3), (6,2), (8,9), (10, 9), (8,12), (14, 15), (14, 10), (6,5), (10,11),( 11, 7), (4,8), (0, 1), (1,2), (12, 13)]

G.add_edges_from(nomes)

val_map = {'A': 0.3,
           'D': 0.3,
           'H': 0.3}

values = [val_map.get(node, 0.55) for node in G.nodes()]

# Specify the edges you want here
red_edges = [('A', 'A'), ('E', 'A')]
edge_colours = ['black' if not edge in red_edges else 'red'
                for edge in G.edges()]
black_edges = [edge for edge in G.edges() if edge not in red_edges]

# Need to create a layout when doing
# separate calls to draw nodes and edges

pos = nx.spring_layout(G)

nx.draw_networkx_nodes(G, pos,node_size = 300)

nx.draw_networkx_labels(G, pos)
nx.draw_networkx_edges(G, pos)
nx.draw_networkx_edges(G, pos)

plt.show()
