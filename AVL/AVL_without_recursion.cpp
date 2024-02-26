#include <iostream>
#include <iomanip>
#include <stack>
#include <algorithm>

using namespace std;

typedef struct node* Ref;
struct node{
    int key;
    int height;
    Ref left;
    Ref right;
};

struct AVL{
    Ref root = nullptr;

    Ref getNode(int key){
        Ref p = new node;
        if(!p) return nullptr;
        p->key = key;
        p->height = 1;
        p->left = nullptr;
        p->right = nullptr;
        return p;
    }

	int height(Ref r){
		if(r == nullptr) return 0;
		return r->height;
	}

	int getBalance(Ref r){
		return height(r->left) - height(r->right);
	}

    Ref search(int key){
        if(root == nullptr) return nullptr;
        Ref r = root;
        while(r != nullptr){
            if(key < r->key) r = r->left;
            else if(key > r->key) r = r->right;
            else return r;
        }
        return nullptr;
    }


    // rotate in case L-L
	Ref LL_rotate(Ref& rotateNode){
		Ref childNode = rotateNode->left;
		rotateNode->left = childNode->right;
		childNode->right = rotateNode;

		rotateNode->height = 1 + max(height(rotateNode->left), height(rotateNode->right));
		childNode->height = 1 + max(height(childNode->left), height(childNode->right));
		return childNode;
	}

	// rotate in case L-R
	Ref LR_rotate(Ref& rotateNode){
		Ref childNode = rotateNode->left;
		Ref graChildNode = childNode->right;
		rotateNode->left = graChildNode->right;
		childNode->right = graChildNode->left;
		graChildNode->left = childNode;
		graChildNode->right = rotateNode;

		rotateNode->height = 1 + max(height(rotateNode->left), height(rotateNode->right));
		childNode->height = 1 + max(height(childNode->left), height(childNode->right));
		graChildNode->height = 1 + max(height(graChildNode->left), height(graChildNode->right));

		return graChildNode;
	}

	//rotate in case R-R
	Ref RR_rotate(Ref& rotateNode){
		Ref childNode = rotateNode->right;
		rotateNode->right = childNode->left;
		childNode->left = rotateNode;

		rotateNode->height = 1 + max(height(rotateNode->left), height(rotateNode->right));
		childNode->height = 1 + max(height(childNode->left), height(childNode->right));

		return childNode;
	}

	// Rotate in case R-L
	Ref RL_rotate(Ref& rotateNode){
		Ref childNode = rotateNode->right;
		Ref graChildNode = childNode->left;
		rotateNode->right = graChildNode->left;
		childNode->left = graChildNode->right;
		graChildNode->left = rotateNode;
		graChildNode->right = childNode;

		rotateNode->height = 1 + max(height(rotateNode->left), height(rotateNode->right));
		childNode->height = 1 + max(height(childNode->left), height(childNode->right));
		graChildNode->height = 1 + max(height(graChildNode->left), height(graChildNode->right));

		return graChildNode;
	}

	Ref balanceTree(Ref& r){
		int balance = getBalance(r);

		if(balance > 1){ // In this case, the tree leans towards the left side.
			if(height(r->left->left) >= height(r->left->right)){
				r = LL_rotate(r);
			}
			else r = LR_rotate(r);
		}
		else if(balance < -1){ // In this case, the tree leans towards the right side
			if(height(r->right->left) <= height(r->right->right)){
				r = RR_rotate(r);
			}
			else r = RL_rotate(r);
		}

		return r;
	}

	void fix_tree(Ref& child, stack<Ref>& path){
		while(!path.empty()){
        	Ref parent = path.top();
        	path.pop();

        	if(parent == nullptr){
        		root = child;
        	}
        	else{
	        	if(child->key < parent->key) parent->left = child;
	        	else parent->right = child;
	        	parent->height = 1 + max(height(parent->left), height(parent->right));

	        	child = parent;
	        	child = balanceTree(child);	
        	}
        }
	}

    void Add(int key){
        if(root == nullptr) {
            root = getNode(key);
            return;
        }

        stack<Ref> path; path.push(nullptr);
        
        Ref child = root;
        while(child != nullptr){
            path.push(child);
            if(key < child->key) {
            	child = child->left;
            }
            else if(key > child->key) child = child->right;
            else return;
        }

        child = getNode(key);

        fix_tree(child, path);
    }

    void findAlterNode(Ref &child, Ref &DelNode, stack<Ref>& path){
        while(child->right) {
            path.push(child);
            child = child->right;
        }

        DelNode->key = child->key;
        DelNode = child;
    }

	void Del(int key){
        stack<Ref> path; path.push(nullptr);

        Ref child = root;
        while(child != nullptr){
            if(key < child->key) {
        		path.push(child);
                child = child->left;
            }
            else if(key > child->key) {
            	path.push(child);
                child = child->right;
            }
            else{
                
	            Ref DelNode = child;

	            if(child->right != nullptr && child->left != nullptr){
	                path.push(child);
	                child = child->left;
	                findAlterNode(child, DelNode, path);
	            }

                child = (child->right == nullptr) ? child->left : child->right;

            	Ref parentDel = path.top(); path.pop();

            	if(parentDel == nullptr){
        			root = child;
        		}
                else{	
	                if(DelNode->key <= parentDel->key) parentDel->left = child;
	                else parentDel->right = child;
	                parentDel->height = 1 + max(height(parentDel->left), height(parentDel->right));
	                child = parentDel;
	                child = balanceTree(child);
                }

               	fix_tree(child, path);

                delete DelNode; DelNode = nullptr;
            }
        }
    }

    void printTree(Ref r, int indent = 0) {
        if (r != nullptr) {
            if (r->right) {
                printTree(r->right, indent + 5);
            }
            if (indent > 0) {
                cout << setw(indent) << " ";
            }
            cout << "[" << r->key << "]" << endl;
            if (r->left) {
                printTree(r->left, indent + 5);
            }
        }
    }

    void printTree(){
        printTree(root);
    }
};


int main(){
    freopen("input.txt", "r", stdin);
    freopen("a.txt", "w", stdout);
    AVL tree;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int key; cin >> key;
        tree.Add(key);
    }

    tree.printTree();

    cout << "\n-----------------------------------\n";

    tree.Del(29);
    tree.Del(25);
    tree.Del(9);
    tree.Del(1);
    // tree.Del(19);
    // tree.Del(33);
    // tree.Del(17);
    // tree.Del(31);
    // tree.Del(21);
    // tree.Del(11);
    // tree.Del(7);
    // tree.Del(5);
    // tree.Del(3);
    // tree.Del(15);
    // tree.Del(13);
    // tree.Del(27);
    tree.printTree();
}
