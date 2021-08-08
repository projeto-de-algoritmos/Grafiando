import networkx as nx
import matplotlib.pyplot as plt

G = open("entradas.csv", 'r')
G = nx.read_edgelist("entradas.csv", delimiter=",")

# plot do grafo
nx.draw(G, with_labels=True, node_size= 1000)
plt.show()