template <typename T>
class DSU {
 private:
  vector<T> rank;
  vector<T> parent;

 public:
  // store other info as required
  DSU(const size_t& n) {
    this->rank.resize(n);
    fill(this->rank.begin(), this->rank.end(), 0);

    this->parent.resize(n);
    iota(this->parent.begin(), this->parent.end(), 0);
  }

  T find(const T& node) {
    //  path compression
    return this->parent[node] = this->parent[node] == node ? node : this->find(this->parent[node]);
  }

  void merge(T node_1, T node_2) {
    node_1 = this->find(node_1);
    node_2 = this->find(node_2);

    //  both the nodes are present in the same set
    if (node_1 == node_2) return;

    //  either of the node can be the parent, so rank will increase
    if (this->rank[node_1] == this->rank[node_2]) ++this->rank[node_1];

    //  higher rank will be the parent (union by rank to reduce complexity)
    this->rank[node_1] < this->rank[node_2] ? this->parent[node_1] = node_2 : this->parent[node_2] = node_1;
  }
};
