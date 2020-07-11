static int findRootToLeafPathNumbers(TreeNode *currentNode, int pathSum) {
    if (currentNode == nullptr) {
      return 0;
    }

 
    pathSum = 10 * pathSum + currentNode->val;


    if (currentNode->left == nullptr && currentNode->right == nullptr) {
      return pathSum;
    }
   
    return findRootToLeafPathNumbers(currentNode->left, pathSum) + 
           findRootToLeafPathNumbers(currentNode->right, pathSum);
  }