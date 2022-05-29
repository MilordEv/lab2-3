#ifndef __AVLTREE__
#define __AVLTREE__

template <typename T>
class AVLTree {
	private:
		struct Node {
			T key;
			unsigned char Height;
			Node* left;
			Node* right;
			Node(T k) : key(k), left(nullptr), right(nullptr), Height(1) {}
		};

		Node* root;
    
	private:
		unsigned char Height(Node* p) {
			if (p) {
				return p->Height;
			} else {
				return 0;
			}
		}

		int Bfactor(Node* p) {
			return Height(p->right)-Height(p->left);
		}

		void FixHeight(Node* p) {
			unsigned char hl = Height(p->left);
			unsigned char hr = Height(p->right);
			
			if (hl > hr) {
				p->Height = hl + 1;
			} else {
				p->Height = hr + 1;
			}
		};

		Node* rotateright(Node* p) {
			Node* q = p->left;
			p->left = q->right;
			q->right = p;
			FixHeight(p);
			FixHeight(q);
			return q;
		}

		Node* Rotateleft(Node* q) {
		Node* p = q->right;
			q->right = p->left;
			p->left = q;
			FixHeight(q);
			FixHeight(p);
			return p;
		}

		Node* Balance(Node* p) {
			FixHeight(p);
			if (Bfactor(p) == 2) {
				if (Bfactor(p->right) < 0) {
					p->right = rotateright(p->right);
				}

				return Rotateleft(p);
			}

			if (Bfactor(p) == -2) {
				if (Bfactor(p->left) > 0) {
					p->left = Rotateleft(p->left);
				}
				
				return rotateright(p);
			}
			return p; 
		}

		Node* Insert(Node* p, T k) {
			if (!p) { 
				return new Node(k);
			}

			if (k < p->key) {
				p->left = Insert(p->left,k);
			} else {
				p->right = Insert(p->right,k);
			}
			return Balance(p);
		}

		bool Find(Node* p, T k) {
			if (!p) {
				return false;
			}

			if (p->key == k) { 
				return true;
			}

			if (k < p->key) {
				return Find(p->left, k);
			} else {
				return Find(p->right, k);
			}
		}

		Node* FindNode (Node* p, T k) {
			if (!p) {
				return nullptr;
			}

			if (p->key == k) { 
				return p;
			}

			if (k < p->key) {
				return FindNode(p->left, k);
			} else {
				return FindNode(p->right, k);
			}
		}

		Node* Findmin(Node* p) {
			if (p->left) {
				return Findmin(p->left);
			} else {
				return p;
			}
		}

		Node* Removemin(Node* p) {
			if (!(p->left)) {
				return p->right;
			}
			p->left = Removemin(p->left);
			return Balance(p);
		}

		Node* Remove(Node* p, T k) {
			if (!p) {
				return 0;
			}
			if (k < p->key) {
				p->left = Remove(p->left,k);
			} else if (k > p->key) {
				p->right = Remove(p->right,k);
			} else  {
				Node* q = p->left;
				Node* r = p->right;
				delete p;

				if (!r) {
					return q;
				}
				Node* min = Findmin(r);
				min->right = Removemin(r);
				min->left = q;
				return Balance(min);
			}
			return Balance(p);
		}

		void CopyTree(AVLTree<T>** copyTree, Node* t) {
			if (t) {
				(*copyTree)->Insert(t->key);
				CopyTree(copyTree, t->left);
				CopyTree(copyTree, t->right);
			}
		}

		void Map(AVLTree<T>** newTree, Node* t, T func(T key)) {
			if (t) {
				(*newTree)->Insert(func(t->key));
				Map(newTree, t->left, func);
				Map(newTree, t->right, func);
			}
		}

		void Where(AVLTree<T>** newTree, Node* t, bool func(T key)) {
			if (t) {
				if (func(t->key)) {
					(*newTree)->Insert(t->key);
				}
				Where(newTree, t->left, func);
				Where(newTree, t->right, func);
			}
		}

		void Reduce(T* value, Node* t, T func(T key, T val)) {
			if (t) {
				*value = func(t->key, *value);
				Reduce(value, t->left, func);
				Reduce(value, t->right, func);
			}
		}

		void clear(Node* p) {
			if (p) {
				clear(p->left);
				clear(p->right);
				delete p;
				p = nullptr;
			}
		}

		void SearchSubtree(bool& ans, Node* p, Node* np) {
			if (p == nullptr && np == nullptr) {
				return;
			}
			if ((p == nullptr && np) || (p && np == nullptr)) {
				ans = false;
				return;
			}
			if (p->value != np->value) {
				ans = false;
				return;
			}
			SearchSubtree(ans, p->left, np->left);
			SearchSubtree(ans, p->right, np->right);
		}

	public:
		void Insert(T k) {
			this->root = Insert(this->root, k);
			return;
		}

		T Findmin() {
			return Findmin(this->root);
		}

		void Remove(T k) {
			this->root = Remove(this->root, k);
			return;
		}

		bool Find(T k) {
			return Find(this->root, k);
		}

		AVLTree<T>* Map(T func(T)) {
			AVLTree<T>* newTree = new AVLTree<T>;
			Map(&newTree, this->root, func);

			return newTree;
		}

		AVLTree<T>* Where(bool func(T)) {
			AVLTree<T>* newTree = new AVLTree<T>;
			Where(&newTree, this->root, func);

			return newTree;
		}

		T Reduce(T func(T v1, T v2), T startValue) {
			T value = startValue;
			Reduce(&value, this->root, func);

			return value;
		}

		AVLTree<T>* GetSubTree(T key) {
			AVLTree<T>* newTree = new AVLTree<T>;
			Node* p = FindNode(this->root, key);
			if (p) {
				CopyTree(&newTree, p);
			}
			return newTree;
		}

		bool SearchSubtree(AVLTree<T>* subTree) {
			bool answer = true;
			this->SearchSubtree(&answer, this->root, subTree->root);
			return answer;
		}

		AVLTree(T key) : root(Node(key)) {}
		AVLTree() : root(nullptr) {}

		AVLTree(const AVLTree<T> &avlTree) {
			this->root = nullptr;
			CopyTree(&this, avlTree.root);
		}

		~AVLTree() {
			clear(this->root);
		}

		void Print(Node* p) {
			if (p) {
				Print(p->left);
				std::cout << p->key << " ";
				Print(p->right);
			}
		}
		void Print() {
			Print(this->root);
		}
};

#endif