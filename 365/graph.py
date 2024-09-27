# graph.py

import networkx as nx
import matplotlib.pyplot as plt

def draw_graph(file_path):
    # グラフの辺を読み込む
    edges = []
    with open(file_path, 'r') as file:
        N = int(file.readline().strip())
        for _ in range(N - 1):
            u, v = map(int, file.readline().split())
            edges.append((u - 1, v - 1))

    # networkxのグラフを作成
    G = nx.Graph()
    G.add_edges_from(edges)

    # グラフの描画
    pos = nx.spring_layout(G)  # レイアウトを設定
    nx.draw(G, pos, with_labels=True, node_size=700, node_color='skyblue', font_size=8, font_color='black', font_weight='bold', edge_color='gray', linewidths=0.5)

    # 描画結果を表示
    plt.show()

# ファイルを指定してグラフを描画
if __name__ == "__main__":
    file_path = "./in.txt"  # ファイルのパスを適切なものに変更
    draw_graph(file_path)
