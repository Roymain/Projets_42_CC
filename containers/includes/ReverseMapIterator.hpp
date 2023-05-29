#pragma once

#include <cstddef>

#include "IteratorTraits.hpp"
#include "MapIterator.hpp"



namespace ft {

	template <class T, class Compare, typename Node>
		class ReverseMapIterator{
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

			ReverseMapIterator(const nodePtr node = 0, const key_comp& comp = key_comp()): _nodePtr(node), _comp(comp){};

			ReverseMapIterator(pointer node, const key_comp& comp = key_comp()): _comp(comp){
				_nodePtr = node;
			};
			
			ReverseMapIterator(const MapIterator< T,  Compare, Node>& it): _comp(it.getComp()){
				_nodePtr = it.getNodePtr();
			};

			template <class W, class Comp, typename Nod>
			ReverseMapIterator(const ReverseMapIterator<W, Comp, Nod> &copy){
				_nodePtr = (Node*)(copy.getNodePtr());
				_comp = (Compare)(copy.getComp());
			};

			~ReverseMapIterator(){};

			MapIterator< T,  Compare, Node> base() {
				return MapIterator< T,  Compare, Node>(_nodePtr, _comp);
			}

			ReverseMapIterator find__min(){
				nodePtr origin = _nodePtr;
				while (origin->parent)
					origin = origin->parent;
				while (origin->left)
					origin = origin->left;
				return origin;

			}
			
			ReverseMapIterator& find__min() const{
				nodePtr origin = _nodePtr;
				while (origin->parent)
					origin = origin->parent;
				while (origin->left)
					origin = origin->left;
				return origin;

			}
			
			nodePtr getNodePtr() const {
				return _nodePtr;
			};

			key_comp getComp() const {
				return _comp;
			};



			bool operator==(const ReverseMapIterator& it) {
				// ReverseMapIterator test = find__min();
				// if (test == it){
				// 	std::cout << "miaou\n";
				// 	return true;
				// }
				return (it._nodePtr == _nodePtr);
			}

			bool operator==(const ReverseMapIterator& it) const {
				if (find__min() == it){
					//std::cout << "miaou\n";
					return true;
				}
				return (it._nodePtr == _nodePtr);
			}

            bool operator!=(const ReverseMapIterator& it) const {
				if (it._nodePtr == _nodePtr)
					return false;
				return (it._nodePtr != _nodePtr);
			}
	
			template <class W, class Comp, typename Nod>
			ReverseMapIterator& operator=(const ReverseMapIterator<W, Comp, Nod>& rhs) {		
				_nodePtr = (Node*)(rhs.getNodePtr());
				_comp = (Compare)(rhs.getComp());
				return (*this);
			}

			reference operator*() const {
				return *(--MapIterator<T, Compare, Node>(_nodePtr, _comp));
			}
			
			pointer operator->() const {
				return (&operator*());
			}

			ReverseMapIterator& operator--(){

				
				nodePtr origin = _nodePtr;
				// if (origin->right->isLast){
				// 	_nodePtr = _nodePtr->right;
				// 	return (*this);
				// }
				//std::cout << _nodePtr->isLast << "\n";
				if (origin == origin->last)
				{
					_nodePtr = _nodePtr->last;
					//std::cout << "vserxvsare1\n";
					return (*this);
				
				}
				//std::cout << "vserxvsare\n";
				if (_nodePtr->right){
					_nodePtr = _nodePtr->right;
					while (_nodePtr->left)
						_nodePtr = _nodePtr->left;
					//std::cout << "vserxvsare2\n";
					return (*this);
				}
				if (_nodePtr->parent){
					_nodePtr = _nodePtr->parent;
					if (_comp(origin->content.first, _nodePtr->content.first))
					{//std::cout << "vserxvsare3\n";
						return (*this);}
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

			ReverseMapIterator operator--(int){
				ReverseMapIterator	copy(*this);
				
				if (copy.getNodePtr()->content.first == '\0'){
					//_nodePtr = _nodePtr->right;
					//std::cout << "vserxvsare\n";
					return copy;
				}

				if (copy.getNodePtr() == NULL){
					_nodePtr = _nodePtr->right;
					return copy;
				}
				if ( _nodePtr == _nodePtr->last)
				{
					_nodePtr = _nodePtr->last->left;
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

			ReverseMapIterator& operator++(){
				nodePtr origin = _nodePtr;
				if ( _nodePtr == _nodePtr->last)
				{
					_nodePtr = _nodePtr->parent;
					return (*this);
				
				}
				if (origin == NULL)
					return (*this);
				if (!_nodePtr->right && !_nodePtr->left && !_comp(_nodePtr->content.first, _nodePtr->parent->content.first)){
					_nodePtr = _nodePtr->parent;
				
				return (*this);
				}
				if (_nodePtr->left && _nodePtr->content.first && _comp(_nodePtr->left->content.first, origin->content.first)){
					_nodePtr = _nodePtr->left;
					while (_nodePtr->right)
						_nodePtr = _nodePtr->right;
					return (*this);
				}
				if (_nodePtr->parent  && _comp(_nodePtr->parent->content.first, origin->content.first)){
					_nodePtr = _nodePtr->parent;

						return (*this);
				}
				while (_nodePtr->parent){
					_nodePtr = _nodePtr->parent;
					if (_comp(_nodePtr->content.first, origin->content.first))
						return (*this);
					if (_comp(_nodePtr->content.first, origin->content.first) && _nodePtr->left){
						_nodePtr = _nodePtr->left;
						while (_nodePtr->right)
							_nodePtr = _nodePtr->right;
						return (*this);
					}
				}
				Node* nul = 0;
				_nodePtr = nul;
				return (*this);
			};

			ReverseMapIterator operator++(int){
				ReverseMapIterator	copy(*this);
				operator++();
				return (copy);
			};



			Node* findMin(Node* t)
    		{
    		    	if(t == NULL)
    					return NULL;
    		    	else if(t->left == NULL)
    		        	return t;
    		    	else
    		        	return findMin(t->left);
    		}


		};
}