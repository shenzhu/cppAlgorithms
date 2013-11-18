/**
 * Returns true if x is found in the tree
 */
template <typename Comparable>
bool contains(const Comparable & x) const
{
	return contains(x, root);
}

/**
 * Insert x into the tree; duplicates are ignored.
 */
template <typename Comparable>
void insert(const Comparable & x)
{
	insert(x, root);
}

/**
 * Remove x from the tree. Nothing is done if x is not found.
 */
template <typename Comparable>
void remove(const Comparable & x)
{
	remove(x, root);
}

/**
 * Internal method to test if an item is in a subtree.
 * x is item to search for.
 * t is the node that roots the subtree.
 */
template <typename Comparable>
bool contains(const Comparable & x, BinaryNode *t) const
{
	if(t == NULL)
		return false;
	else if(x < t->element)
		return contains(x, t->left);
	else if(x > t->element)
		return contains(x, t->right);
	else
		return true;
}


/**
 * Internal method to find the smallest item in a subtree t.
 * Return node containing the smallest item.
 */
 BinaryNode * findMin(BinaryNode *t) const
 {
 	if(t == NULL)
 		return NULL;
 	if(t->left == NULL)
 		return t;
 	return findMin(t->left);
 }


/**
 * Internal method to find the larget item in a subtree t.
 * Return node containing the largest item
 */
 BinaryNode * findMax(BinaryNode *t) const
 {
  	if(t != NULL)
  	{
  		while(t->right != NULL)
  			t = t->right;
  	}
	 return t;
 }


/**
 * Internal method to insert into a subtree
 * x is the item to insert.
 * t is the node that roots the subtree
 * Set the new root of the subtree.
 */
 template <typename Comparable>
 void insert(const Comparable & x, BinaryNode * & t)
 {
 	if(t == NULL)
 		t = new BinaryNode(x, NULL, NULL);
 	else if(x < t->element)
 		insert(x, t->left);
 	else if(x > t->element)
 		insert(x, t->right);
 	else
 		; // duplicate, do nothing
 }


/**
 * Internal method to remove from a subtree.
 * x is the item to remove
 * t is the node that roots the subtree
 * Set the new root of the subtree.
 */
 template <typename Comparable>
 void remove(const Comparable & x, BinaryNode * & t)
 {
 	if(t == NULL)
 		return;
 	if(x < t->element)
 		remove(x, t->left);
 	else if(x > t->element)
 		remove(x, t->right);
 	else if(t->left != NULL && t->right != NULL)
 	{
 		t->element = findMin(t->right)->element;
 		remove(t->element, t->right);
 	}
 	else
 	{
 		BinaryNode * oldNode = t;
 		t = (t->left != NULL) ? t->left : t->right;
 		delete oldNode;
 	}
 }


/**
 * Destructor for the tree.
 */
 ~BinarySearchTree()
 {
 	makeEmpty();
 }


/**
 * Internal method to make subtree empty.
 */
 void makeEmpty(BinaryNode * & t)
 {
 	if(t != NULL)
 	{
 		makeEmpty(t->left);
 		makeEmpty(t->right);
 		delete t;
 	}
 	t = NULL;
 }


/**
 * Deep copy
 */
 const BinarySearchTree & operator=(const BinarySearchTree & rhs)
 {
 	if(this != &rhs)
 	{
 		makeEmpty();
 		root = clone(rht.root);
 	}
 	return *this;
 }


/**
 * Internal method to clone subtree.
 */
 BinaryNode * clone(BinaryNode *t) const
 {
 	if(t == NULL)
 		return NULL;

 	return new BinaryNode(t->element, clone(t->left), clone(t->right));
 }