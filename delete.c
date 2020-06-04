void concreteDeletionParentNonNULLCase(RBTree *tree, Node** nodeToDelete, Node* nodeOfChild)
{
    if ((*nodeToDelete)->parent->right != *nodeToDelete)
    {

        (*nodeToDelete)->parent->left = nodeOfChild;
        if (nodeOfChild != NULL)
        {
            nodeOfChild->parent = (*nodeToDelete)->parent;
        }
        tree->freeFunc((*nodeToDelete)->data);
        free(*nodeToDelete);
        *nodeToDelete = NULL;
    }
    else
    {
        (*nodeToDelete)->parent->right = nodeOfChild;
        if (nodeOfChild != NULL)
        {
            nodeOfChild->parent = (*nodeToDelete)->parent;
        }
        tree->freeFunc((*nodeToDelete)->data);
        free(*nodeToDelete);
        *nodeToDelete = NULL;
    }
    /**
    tree->freeFunc((*nodeToDelete)->data);
    free(*nodeToDelete);
    *nodeToDelete = NULL;
     */
}
void concreteDeletionParentNULLCase(RBTree *tree, Node** nodeToDelete, Node* nodeOfChild)
{
    tree->freeFunc(tree->root->data);
    free(tree->root);

    if (nodeOfChild != NULL)
    {
        nodeOfChild->parent = NULL;
    }
    tree->root = nodeOfChild;
}

void concreteDeletionCases(RBTree *tree, Node** nodeToDelete, Node* nodeOfChild)
{
    if ((*nodeToDelete)->parent == NULL)
    {
        concreteDeletionParentNULLCase(tree, nodeToDelete, nodeOfChild);
    }
    else
    {
        concreteDeletionParentNonNULLCase(tree, nodeToDelete, nodeOfChild);
    }
}
