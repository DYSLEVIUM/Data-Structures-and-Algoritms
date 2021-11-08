template <typename T>
class DSU {
 private:
  vector<T> rank;
  vector<T> parent;

 public:
  // store other info as required
  DSU(const size_t& n) {
    this->rank.resize(n);
    fill(all(this->rank), 0);

    this->parent.resize(n);
    iota(all(this->parent), 0);
  }

  T find(const T& node) {
    //  path compression
    return this->parent[node] = (this->parent[node] == node ? node : this->find(this->parent[node]));
  }

  void merge(T node1, T node2) {
    node1 = this->find(node1);
    node2 = this->find(node2);

    //  both the nodes are present in the same set
    if (node1 == node2) return;

    //  either of the node can be the parent, so rank will increase
    if (this->rank[node1] == this->rank[node2]) ++(this->rank[node1]);

    //  higher rank will be the parent (union by rank to reduce complexity)
    this->rank[node1] < this->rank[node2] ? this->parent[node1] = node2 : this->parent[node2] = node1;
  }
};
