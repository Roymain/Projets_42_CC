#pragma once

#include <cstddef>

#include "IteratorTraits.hpp"



namespace ft {

	template <class T, class Compare, typename Node>
		class MapIterator{
			public:
    			typedef std::bidirectional_iterator_tag		iterator_category;
    			typedef T         		value_type;
    			typedef ptrdiff_t  		difference_type;
    			typedef T*   		pointer;
    			typedef T&		reference;
				typedef Compare			key_comp;
				typedef Node*			nodePtr;

			private:
					nodePtr		_nodePtr;
					key_comp	_comp;

			public:

			MapIterator(const nodePtr node = 0, const key_comp& comp = key_comp()): _nodePtr(node), _comp(comp){};

			template <class W, class Comp, typename Nod>
			MapIterator(Node* node = 0, Comp & comp = Comp()): _nodePtr((nodePtr)node), _comp((key_comp)comp){};

			MapIterator(pointer node, const key_comp& comp = key_comp()): _comp(comp){
				_nodePtr = node;
			};

			template <class W, class Comp, typename Nod>
			MapIterator(const MapIterator<W, Comp, Nod> &copy){
				_nodePtr = (Node*)(copy.getNodePtr());
				_comp = (Compare)(copy.getComp());
			};


			~MapIterator(){};


			
			nodePtr getNodePtr() const {
				return _nodePtr;
			};

			key_comp getComp() const {
				return _comp;
			};



			bool operator==(const MapIterator& it) const {
				return (it._nodePtr == _nodePtr);
			}

            bool operator!=(const MapIterator& it) const {

				return (it._nodePtr != _nodePtr);
			}
	

			template <class W, class Comp, typename Nod>
			MapIterator& operator=(const MapIterator<W, Comp, Nod>& rhs) {
				
				_nodePtr = (Node*)(rhs.getNodePtr());

				_nodePtr->left = (Node*)(rhs.getNodePtr()->left);
				_nodePtr->parent = (Node*)(rhs.getNodePtr()->parent);
				_nodePtr->last = (Node*)(rhs.getNodePtr()->last);
				_comp = (Compare)(rhs.getComp());
				return (*this);
			}
			
	

			reference operator*() const {
				return _nodePtr->content;
			}
			
			pointer operator->() const {
				return (&_nodePtr->content);
			}

			MapIterator& operator++(){
				nodePtr origin = _nodePtr;
				if (_nodePtr->right){
					_nodePtr = _nodePtr->right;
					while (_nodePtr->left)
						_nodePtr = _nodePtr->left;
					return (*this);
				}
				if (_nodePtr->parent){
					_nodePtr = _nodePtr->parent;
					if (_comp(origin->content.first, _nodePtr->content.first))
						return (*this);
				}
				else{
					_nodePtr = _nodePtr->last;
					return (*this);
				}
				while (!_comp(origin->content.first, _nodePtr->content.first)){
					if (_nodePtr->right && _comp(origin->content.first, _nodePtr->right->content.first) && _nodePtr->right != origin){
						_nodePtr = _nodePtr->right;
						return (*this);
					}
					if (_nodePtr->parent)
						_nodePtr = _nodePtr->parent;
					else
					{
						_nodePtr = _nodePtr->last;
						return (*this);
					}
					if (_comp(origin->content.first, _nodePtr->content.first)){
						return (*this);
					}
				}
				
				return (*this);

			};

			MapIterator operator++(int){
				MapIterator	copy(*this);
				
				if (copy.getNodePtr() == NULL){
					_nodePtr = _nodePtr->right;
					return copy;
				}
				if ( _nodePtr == _nodePtr->last)
				{
					_nodePtr = _nodePtr->parent;
					return (copy);
				
				}

				if (_nodePtr->right){
					_nodePtr = _nodePtr->right;
					while (_nodePtr->left)
						_nodePtr = _nodePtr->left;
			
					return (copy);
				}
				if (_nodePtr->parent){
					_nodePtr = _nodePtr->parent;
					if (_comp(copy._nodePtr->content.first, _nodePtr->content.first))
						return copy;
				}
				else{
					_nodePtr = _nodePtr->last;
					return copy;
				}
				while (!_comp(copy._nodePtr->content.first, _nodePtr->content.first)){
					if (_nodePtr->right && _comp(copy._nodePtr->content.first, _nodePtr->right->content.first) && _nodePtr->right != copy._nodePtr){
						_nodePtr = _nodePtr->right;
						return (copy);
					}
					if (_nodePtr->parent)
						_nodePtr = _nodePtr->parent;
					else
					{
						////std::cout << "gnas\n";
						_nodePtr = _nodePtr->last;
						return (copy);
					}
					if (_comp(copy._nodePtr->content.first, _nodePtr->content.first)){
						return (copy);
					}
				}
				return (copy);
			};

			MapIterator &operator--(){
				_nodePtr = __prev(_nodePtr);
				return (*this);
			}

			MapIterator operator--(int){
				MapIterator ret(*this);
				//ret = __prev(_nodePtr);
				operator--();
				return (ret);
			}

		private:
			Node* __findMin(Node* t)
    			{
    			    	if(t == NULL)
    						return NULL;
    			    	else if(t->left == NULL)
    			        	return t;
    			    	else
    			        	return __findMin(t->left);
    			}
    			
    			Node* __findMax(Node* t)
    			{
		
    				if(t == NULL)
    			    		return NULL;
    				else if(t->right == NULL)
    			    	    	return t;
    				else
    			    	    	return __findMax(t->right);
    			}

    			Node* __findRoot(Node* t)
    			{
    				if(t == NULL)
    			    		return NULL;
    				else if(t->parent == NULL)
    			    	    	return t;
    				else
    			    	    	return __findRoot(t->parent);
    			}

			Node* __next(Node *t)
			{
				if(t == NULL)
					return NULL;
				else if(t->right != NULL)
					return __findMin(t->right);
				else
				{
					Node *p = t->parent;
					while(p != NULL && t == p->right)
					{
						t = p;
						p = p->parent;
					}
					return p;
				}
			}

			Node* __prev(Node *t)
			{
				if(t == t->last){
					Node *p = t->parent;
					return p;
				}

				if(t == NULL)
					return NULL;
				if(t->isLast){
					Node *p = t->parent;
					return p;
				}
				if(t->left != NULL)
					return __findMax(t->left);
				else
				{
					Node *p = t->parent;
					while(p != NULL && t == p->left)
					{
						t = p;
						p = p->parent;
					}
					return p;
				}
			}
	};
}