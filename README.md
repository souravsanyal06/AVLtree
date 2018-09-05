AVL tree is a self-balancing binary search tree. In such a tree, the difference between the heights of two child sub-trees of any node, i.e, balance factor should not be more than 1. If anytime this balance factor is more than 1, then re-balancing of the tree should be performed. The re-balancing of the tree is done by one or more tree rotations. To understand tree-rotations better: http://en.wikipedia.org/wiki/Tree_rotation

To help you start, create node for AVL tree that consists of the following:
            int data
            int height
            AVLnode left
            AVLnode right
            AVLnode parent

   Programming Assignment (100 Points): Here you are required to program an AVL Tree that can perform the following action:
        Creating tree
        Insertion of a node
        Deletion of a node
        Searching a node
        Deleting Tree
        Traversal of the tree - Pre-order, Post-order and In-order
        Check Balance
        
   To understand these actions more clearly, you check this USU AVL link: http://csilm.usu.edu/lms/nav/activity.jsp?sid=__shared&cid=usu@mills&lid=16 (You choose the step-by-step in "options" tab to understand each step clearly)

   Input Format: Your program should first print out the actions that can be performed:
    Ex: Choose the option to be performed:
                   1. Create_Tree
                   2. Insertion
                   3. Deletion
                   4. Search
                   5. Traversal
                   6. Delete_Tree
                   7. Check_Balance
    This input option should be of int type only
        Create Tree:
        This option should create a tree by reading an input file, attached below, which contains of one integer per line that creates the tree.
        The example input file is attached here (15 integers): Input.txt
        Every time this option is chosen, the existing tree should be deleted (delete_tree()) and a tree with the given input file should be created.
        Insertion:      
        This option should insert a node in the existing tree. The input integer value should be typed in by the user.
        If no tree has been created before this option then the entered integer value should be inserted anyway.
        By using this option multiple times, you should be able to create a tree.
        Deletion:
        This option should delete a node from the existing tree. The input integer value should be typed in by the user.
        If no tree has been created before this option, the program should print out "Node cannot be deleted. Empty Tree!"
        If the entered integer value is not found in the created tree, the program should print out "Node cannot be found. Deletion cannot be performed"
        Search:
        This option should search a node in the existing tree. The input integer value should be typed in by the user.
        Traversal:
        Selecting this option should print out the options to choose the type of traversal to be performed:
            Pre_order
            Post_order
            Post_order
        The input to choose the type of traversal should be of int value.
        Delete_Tree:
        Choosing this option should delete the whole existing tree. No inputs required.
        Check_Balance:
        This option should not take any input. It should just check if the balance_factor (as mentioned above) is 1 or more.
        If the balance_factor > 1, tree_rotation operations should be performed to balance the tree.
        This operation should be performed automatically after every create_tree, insertion and deletion operation to check if the tree is an AVL tree (balance_factor = 1) or not.
    Output Format: The output should be printed on your console. Make sure it clearly prints the actions as follows:
        Create Tree:
        After creating the tree, this option should print the values of the tree in Pre-order traversal.
        Insertion:
        After inserting a node, this option should print the updated tree in Pre-order traversal.
        Deletion:
        After deleting a node, this option should print the updated tree in Pre-order traversal.
        Search:
        This option should print the position, i.e, height at which the node was found.
        Traversal:
        This option should print the tree for the chosen type of traversal.
        Delete_Tree:
        After successfully, deleting the whole tree, this option should just print "Tree Deleted"
        Check_balance:
        This option should print the balance_factor every time its performed.

   Submission: Please submit a .tar file that contains the following:
        Input file (Keep this file same as the one attached above. Please do not submit your own created input file)
        Your code (all *.h and *.cpp files that you have written)
        Executable file (.exe file)

   Grading: The assignment will be graded on the following criteria:
        Correct Execution (90 Points) - We will be testing your program for different input files. Your program should compile      and execute properly, without any errors and warnings for every input.
            Create tree (10 Points)
            Insertion (20 Points)
            Search (10 Points)
            Deletion (20 Points)
            Traversal (5 Points for each traversal - Total 15 Points)
            Delete_Tree (5 Points)
            Check_Balance (10 Points)
        Code commenting (10 Points) - will be awarded for properly commenting the code
