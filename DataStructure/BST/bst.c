/*
 * This file is where you should implement your binary search tree.  It already
 * contains skeletons of the functions you need to implement (along with
 * documentation for each function).  Feel free to implement any additional
 * functions you might need.  Also, don't forget to include your name and
 * @oregonstate.edu email address below.
 *
 * Name:
 * Email:
 */

#include <stdlib.h>
#include <stdio.h> 
#include "bst.h"

/*
 * This structure represents a single node in a BST.  In addition to containing
 * pointers to its two child nodes (i.e. `left` and `right`), it contains two
 * fields representing the data stored at this node.  The `key` field is an
 * integer value that should be used as an identifier for the data in this
 * node.  Nodes in the BST should be ordered based on this `key` field.  The
 * `value` field stores data associated with the key.
 *
 * You should not modify this structure.
 */
struct bst_node
{
  int key;
  void* value;
  struct bst_node* left;
  struct bst_node* right;
};


/*
 * This structure represents an entire BST.  It specifically contains a
 * reference to the root node of the tree.
 *
 * You should not modify this structure.
 */
struct bst
{
  struct bst_node* root;
};

/*
 * This function should allocate and initialize a new, empty, BST and return
 * a pointer to it.
 */
struct bst* bst_create()
{
  struct bst_node* my_bst_node = malloc(sizeof(struct bst_node));
  my_bst_node->key = 0;
  my_bst_node->value = NULL;
  my_bst_node->left = NULL;
  my_bst_node->right = NULL;

  struct bst* my_bst = malloc(sizeof(struct bst));
  my_bst->root = my_bst_node;
  return my_bst;
}

/*
 * This function should free the memory associated with a BST.  While this
 * function should up all memory used in the BST itself, it should not free
 * any memory allocated to the pointer values stored in the BST.  This is the
 * responsibility of the caller.
 *
 * Params:
 *   bst - the BST to be destroyed.  May not be NULL.
 */


void bst_free(struct bst* bst)
{
  free(bst->root);
  free(bst);
}

/*
 * This function should return the total number of elements stored in a given
 * BST.
 *
 * Params:
 *   bst - the BST whose elements are to be counted.  May not be NULL.
 */
int bst_count(struct bst_node* node)
{
    if (node == NULL)
        return 0;
    else
        return(bst_count(node->right) + 1 + bst_count(node->left));
}
int bst_size(struct bst* bst)
{
  return bst_count(bst->root);
}

/*
 * This function should insert a new key/value pair into the BST.  The key
 * should be used to order the key/value pair with respect to the other data
 * stored in the BST.  The value should be stored along with the key, once the
 * right location in the tree is found.
 *
 * Params:
 *   bst - the BST into which a new key/value pair is to be inserted.  May not
 *     be NULL.
 *   key - an integer value that should be used to order the key/value pair
 *     being inserted with respect to the other data in the BST.
 *   value - the value being inserted into the BST.  This should be stored in
 *     the BST alongside the key.  Note that this parameter has type void*,
 *     which means that a pointer of any type can be passed.
 */

void bst_insert(struct bst* bst, int key, void* value)
{
  if (bst==NULL)
    return;
  struct bst_node *current_node = NULL;
  current_node = bst->root;
  // printf("2:current_node=%p\n",current_node);
  // printf("2:bst->root=%p\n",bst->root);
  printf("2:current_node->key=%d\n",current_node->key);
  // printf("2:bst->root->key=%d\n",bst->root->key);
  // printf("(int )(value) = %d \n",*((int *)(value)));
  if(current_node->value == NULL)
  {
    current_node->key = key;
    current_node->value = value;
    printf("is NULL: current_node->value = %d \n",*((int *)current_node->value));
  }
  else
  {
    // printf("is not NULL: current_node->value = %d \n",*((int *)current_node->value));
    while(current_node != NULL)
    {
      // printf("1\n");
      // printf("current_node->value = %d \n",*((int *)current_node->value));
      if(*((int *)value) < *((int *)(current_node->value)))
      {
        // printf("1\n");
        if(current_node->left!=NULL)
        {
          // printf("2\n");
          current_node = current_node->left;
          // printf("left:key=%d,value = %d\n", key, *((int *)value));
        }
        else
        {
          // printf("3\n");
          struct bst_node *new_node = malloc(sizeof(struct bst_node));
          new_node->key = key;
          new_node->value= value;
          new_node->right = NULL;
          new_node->left = NULL;
          current_node->left = new_node;
          // printf("inserted:%d",*(int *)value);
          // printf("3:current_node->left=%d\n",*(int *)current_node->left);
          // printf("3:bst->root->left=%d\n",*(int *)bst->root->left);
          break;
          // printf("3:current_node->right=%d\n",*(int*)current_node->right);
        }
      }
      else
      {
        if(current_node->right!=NULL)
        {
          // printf("4\n");
          current_node = current_node->right;
          // printf("right:key=%d,value = %d\n", key, *((int *)value));
        }
        else
        {
          // printf("5\n");
          struct bst_node *new_node = malloc(sizeof(struct bst_node));
          new_node->key = key;
          new_node->value= value;
          new_node->right = NULL;
          new_node->left = NULL;
          current_node->right = new_node;
          // printf("inserted:%d",*(int *)value);
          break;
        }
      }
      // printf("2\n");
    }
    // printf("2\n");
    // printf("2\n");
    // printf("new_node->value = %d\n",*((int *)(new_node->value)));
  }
  // printf("-----\n");
  // if(bst->root->left!=NULL)
  //   printf("bst->root->left->value = %d\n",*((int *)(bst->root->left->value)));
  // if(bst->root->right!=NULL)
  //   printf("bst->root->right->value = %d\n",*((int *)(bst->root->right->value)));
  // if(bst->root->left!=NULL)
  //   if(bst->root->left->left!=NULL)
  //     printf("bst->root->left->left->value = %d\n",*((int *)(bst->root->left->left->value)));

  // if(bst->root->left!=NULL)
  //   if(bst->root->left->right!=NULL)
  //     printf("bst->root->left->left->value = %d\n",*((int *)(bst->root->left->right->value)));

}

/*
 * This function should remove a key/value pair with a specified key from a
 * given BST.  If multiple values with the same key exist in the tree, this
 * function should remove the first one it encounters (i.e. the one closest to
 * the root of the tree).
 *
 * Params:
 *   bst - the BST from which a key/value pair is to be removed.  May not
 *     be NULL.
 *   key - the key of the key/value pair to be removed from the BST.
 */

struct bst_node* minValueNode(struct bst_node* node)
{
    struct bst_node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}

struct bst_node* bst_remove_core(struct bst_node* root, int key)
{
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = bst_remove_core(root->left, key);
    else if (key > root->key)
        root->right = bst_remove_core(root->right, key);
    else 
    {
        // node with only one child or no child
        if (root->left == NULL) 
        {
            struct bst_node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) 
        {
            struct bst_node* temp = root->left;
            free(root);
            return temp;
        }
        struct bst_node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = bst_remove_core(root->right, temp->key);
    }
    return root;
}

void bst_remove(struct bst* bst, int key)
{
    bst_remove_core(bst->root,key);
}
/*
 * This function should return the value associated with a specified key in a
 * given BST.  If multiple values with the same key exist in the tree, this
 * function should return the first one it encounters (i.e. the one closest to
 * the root of the tree).  If the BST does not contain the specified key, this
 * function should return NULL.
 *
 * Params:
 *   bst - the BST from which a key/value pair is to be removed.  May not
 *     be NULL.
 *   key - the key of the key/value pair whose value is to be returned.
 *
 * Return:
 *   Should return the value associated with the key `key` in `bst` or NULL,
 *   if the key `key` was not found in `bst`.
 */
void* bst_get(struct bst* bst, int key)
{
  struct bst_node *cur =  bst->root;
  while(cur!=NULL)
  {
    if (key < cur->key)
    {
      cur = cur->left;
    }
    else if (key > cur->key)
    {
      cur = cur->right;
    }
    else if(key == cur->key)
    {
      return cur->value;
    }
  }
  return NULL;
}