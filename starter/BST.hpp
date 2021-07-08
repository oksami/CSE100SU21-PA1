#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream>
using namespace std;

template<typename Data>
class BST {

   protected:

      /** Pointer to the root of this BST, or 0 if the BST is empty */
      BSTNode<Data>* root;

      /** Number of Data items stored in this BST. */
      unsigned int isize;

      /** Height of this BST. */
      unsigned int iheight;

   public:

      /** define iterator as an aliased typename for BSTIterator<Data>. */
      typedef BSTIterator<Data> iterator;

      /** Default constructor.
        * Initialize an empty BST.
        */
      BST() : root(0), isize(0), iheight(-1) {  }


      /** Default destructor.
        * Delete every node in this BST.
        */
      virtual ~BST() {
         deleteAll(root);
      }

      /** Given a reference to a Data item, insert a copy of it in this BST.
       *  Return  true if the item was added to this BST
       *  as a result of this call to insert,
       *  false if an item equal to this one was already in this BST.
       *  Note: This function should use only the '<' operator when comparing
       *  Data items. (should not use ==, >, <=, >=)  For the reasoning
       *  behind this, see the assignment writeup.
       *  TODO
       */
      virtual bool insert(const Data& item) {	//item is a reference to a Data type constant
        	int dummy = 0;
	if(empty() == true){			//empty tree so item will be root
		this->root = new BSTNode<Data>(item);
		isize = isize + 1;
		iheight = 0;
		return true;
	}
	BSTNode<Data>* current = this->root;	//start at root
	while( current->data != item ){		//am I supposed to use the iterator class' != operator here?
		if( (item < current->data) == true){
			if(current->left == nullptr){	//if no left child exists, insert item as left child
				current->left = new BSTNode<Data>(item);
				current->left->parent = current;
				dummy++;
				break; //return true;
			}
			else{				//if left child exists, traverse left
				current = current->left;
				dummy++;
			}
		}
		else if( (item < current->data) == false){	
			if(current->right == nullptr){	//if no right child exists, insert item as right child
				current->right = new BSTNode<Data>(item);
				current->right->parent = current;
				dummy++;
				break; //return true;
			}
			else{				//if right child exists, traverse right
				current = current->right;
				dummy++;
			}
		}
		else return false;				//only reach here if current == item, and cannot have duplicates
	}
	if( iheight<dummy) iheight=dummy;
	isize++;
	return true;
      }


      /** Find a Data item in the BST.
       *  Return an iterator pointing to the item, or pointing past
       *  the last node in the BST if not found.
       *  Note: This function should use only the '<' operator when comparing
       *  Data items. (should not use ==, >, <=, >=).  For the reasoning
       *  behind this, see the assignment writeup.
       *  TODO
       */
      virtual iterator find(const Data& item) const {
      	BSTNode<Data>* current = this->root;
	while( current->data != item){
		if( item < current->data){		//if item < current, traverse left
			current = current->left;
		}
		else if( current->data < item ){	//if current < item, traverse right
			current = current->right;
		}
		return current;
	}
	return end();			//return past last node if not found
      }


      /** Return the number of items currently in the BST.
       *  TODO 
       */
      unsigned int size() const {
         return isize;
      }

      /** Return the height of the BST.
       * The height of an empty tree is -1 and the height of a tree
       * with only one node is 0.
       *  TODO  
       */
      unsigned int height() const {
         return iheight;
      }


      /** Return true if the BST is empty, else false.
       */
      bool empty() const {
         return isize == 0;
      }

      /** Return an iterator pointing to the first item in the BST (not the root).
       */
      iterator begin() const {
         return BST::iterator(first(root));
      }

      /** Return an iterator pointing past the last item in the BST.
       */
      iterator end() const {
         return typename BST<Data>::iterator(0);
      }


      /** Inorder traverse BST, print out the data of each node in ascending order.
       * Implementing inorder and deleteAll base on the pseudo code is an easy way to get started.
       * Pseudo Code:
       * if current node is null: return;
       * recursively traverse left sub-tree
       * print current node data
       * recursively traverse right sub-tree
       * TODO
       */
      void inorder() const {
	if( this->root == nullptr) return;
	this->root->left.inorder();
	std::cout<<this->root->data<<std::endl;
	this->root->right.inorder();
	
      }


   private:

      /** Find the first element of the BST
       *  TODO 
       */ 
      static BSTNode<Data>* first(BSTNode<Data>* root) {
	if( root == nullptr ) return nullptr;
	while( root->left != nullptr)
		root = root->left;
	return root;
      }

      //** do a postorder traversal, deleting nodes
      // *   TODO 	
       
      static void deleteAll(BSTNode<Data>* n) {
         /* Pseudo Code:
            if current node is null: return;
            recursively delete left sub-tree
            recursively delete right sub-tree
            delete current node
            */
      	if( n == nullptr) return;		//if current node is null: return;
	deleteAll(n->left);		//recursively delete left sub-tree
	deleteAll(n->right);		//recursively delete right sub-tree
	delete n;			//delete current node
		
	}


};


#endif //BST_HPP
