# Tree

# Apa Itu Tree?

**Tree** merupakan salah satu bentuk **struktur data** non-linear yang menggambarkan hubungan yang bersifat hirarkis (hubungan one to many) antara elemen-elemen.

![m2-4](https://user-images.githubusercontent.com/86661387/222437488-47843965-7a1c-4ec5-8af0-4f4a89dd4035.png)

> Gambar oleh Paddy3118 - Own work, CC BY-SA 4.0, <https://commons.wikimedia.org/w/index.php?curid=83223854>

**Tree** bisa didefinisikan sebagai kumpulan node dengan elemen khusus yang disebut Root dan referensi ke node lain yang disebut dengan Child. Suatu node dari tree bersama dengan seluruh node di bawahnya membentuk sebuah subtree. Subtree dari sebuah tree juga merupakan sebuah tree.

> Binary Search Tree tidak memiliki implementasi STL dalam bahasa C++

## Terminologi

![tree-parts](https://user-images.githubusercontent.com/86661387/222440636-2b99c1d7-cc3d-4438-ab78-a98f9a2b96a1.jpg)

> Sumber Gambar: <https://adrianmejia.com/images/tree-parts.jpg>

- **Root** - merupakan node paling atas (node pertama) dari sebuah tree.
- **Edge** - merupakan referensi yang menghubungkan antar dua node.
- **Child** - merupakan ekstensi (node yang berada di bawahnya) dari sebuah node.
- **Parent** - merupakan node yang berada di atas dari sebuah node. Seluruh node pasti mempunyai parent kecuali root node.
- **Siblings** - merupakan kumpulan dua atau lebih node yang mempunyai parent yang sama.
- **Leaf** - merupakan node yang tidak mempunyai child.
- **Internal node** - merupakan semua node yang **tidak termasuk leaf** dan **root**.

## Binary Tree

**Binary Tree** merupakan tree yang tiap-tiap nodenya mempunyai paling banyak dua child (left child dan right child).

![m2-5](https://user-images.githubusercontent.com/86661387/222437731-e463c3db-a150-4e84-a535-f1c9686e7db9.png)

> Sumber Gambar: <https://media.geeksforgeeks.org/wp-content/uploads/binary_tree-1.png>

# Binary Search Tree

**Binary Search Tree (BST)** adalah struktur data Binary Tree berbasis node yang memiliki properti berikut:

- Subtree kiri dari sebuah node hanya berisi node dengan key **lebih kecil** dari key node.
- Subtree kanan sebuah node hanya berisi node dengan key **lebih besar** dari key node.
- Subtree kiri dan kanan masing-masing juga harus berupa BST.

![bst-vs-not-bst](https://user-images.githubusercontent.com/86661387/222438928-93d43a66-57d2-44b4-aed9-222fdca6ee5c.jpg)

> Sumber Gambar: <https://cdn.programiz.com/sites/tutorial2program/files/bst-vs-not-bst.jpg>

## Implementasi Binary Search Tree

[**Link Implementasi Lengkap `Binary Search Tree` dapat dilihat di sini**](https://github.com/AlproITS/StrukturData/)

### Representasi Node

**Sebuah node** dalam Binary Search Tree paling dasar mempunyai properti:

- Data atau _key_ yang disimpan,
- Referensi ke node kiri (left), dan
- Referensi ke node kanan (right).

```c
typedef struct bstnode_t {
    int key;
    struct bstnode_t \
        *left, *right;
} BSTNode;
```

### Struktur BST

```c
typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;
```

- ### Find

  Untuk melakukan pencarian sebuah key pada Binary Search Tree, dapat kita lakukan secara rekursif maupun iteratif. Implementasi kali ini akan menggunakan cara iteratif.

  **Utility Function**

  ```c
  BSTNode* __search(BSTNode *root, int value) {
      while (root != NULL) {
          if (value < root->key)
              root = root->left;
          else if (value > root->key)
              root = root->right;
          else
              return root;
      }
      return root;
  }
  ```

  **Primary Function**

  ```c
  bool bst_find(BST *bst, int value) {
      BSTNode *temp = __search(bst->_root, value);
      if (temp == NULL)
          return false;

      if (temp->key == value)
          return true;
      else
          return false;
  }
  ```

  **Contoh**

  ![bst-search](https://user-images.githubusercontent.com/86661387/222438913-0dcd12f1-eb6a-4c21-803d-5f508dca152a.jpg)

  > Sumber Gambar: <https://cdn.programiz.com/sites/tutorial2program/files/bst-search-downward-recursion-step.jpg>

- ### Insert

  Key baru selalu dimasukkan pada leaf. Kita mulai mencari key dari root hingga kita menyentuh node leaf. Setelah node leaf ditemukan, node baru ditambahkan sebagai anak dari node leaf.

  **Utility Function**

  ```c
  BSTNode* __insert(BSTNode *root, int value) {
      if (root == NULL)
          return __createNode(value);

      if (value < root->key)
          root->left = __insert(root->left, value);
      else if (value > root->key)
          root->right = __insert(root->right, value);

      return root;
  }
  ```

  **Primary Function**

  ```c
  void bst_insert(BST *bst, int value) {
      if (!bst_find(bst, value)) {
          bst->_root = __bst__insert(bst->_root, value);
          bst->_size++;
      }
  }
  ```

  **Contoh**

  ![bst-insert](https://user-images.githubusercontent.com/86661387/222438884-fda92ebd-f72b-4b1e-b38a-549a12b5b668.jpg)

  > Sumber Gambar: <https://cdn.programiz.com/sites/tutorial2program/files/bst-downward-recursion-step.jpg>

- ### Remove

  **Utility Function**

  FindMinNode :

  ```c
  BSTNode* __findMinNode(BSTNode *node) {
      BSTNode *currNode = node;
      while (currNode && currNode->left != NULL)
          currNode = currNode->left;

      return currNode;
  }
  ```

  Remove :

  ```c
  BSTNode* __remove(BSTNode *root, int value) {
      if (root == NULL) return NULL;

      if (value > root->key)
          root->right = __remove(root->right, value);
      else if (value < root->key)
          root->left = __remove(root->left, value);
      else {

          if (root->left == NULL) {
              BSTNode *rightChild = root->right;
              free(root);
              return rightChild;
          }
          else if (root->right == NULL) {
              BSTNode *leftChild = root->left;
              free(root);
              return leftChild;
          }

          BSTNode *temp = __findMinNode(root->right);
          root->key     = temp->key;
          root->right   = __remove(root->right, temp->key);
      }
      return root;
  }
  ```

  **Primary Function**

  ```c
  void bst_remove(BST *bst, int value) {
      if (bst_find(bst, value)) {
          bst->_root = __bst__remove(bst->_root, value);
          bst->_size--;
      }
  }
  ```

## Skewed Tree

Apabila urutan insertion tree kalian 1 2 3 4 5 6 7, maka bentuk tree akan seperti gambar di bawah, dan ini dinamakan **Skewed Tree**.

![m2-1](https://user-images.githubusercontent.com/86661387/222437354-185b4382-646c-4491-b7e0-9abccfeff844.png)

> Binary Search Tree akan menjadi _skewed_ apabila urutan insertionnya berupa sekuens yang telah urut (baik ascending maupun descending). Skewed BST merupakan bentuk BST yang paling tidak seimbang.

Urutan insertion pada BST, akan mempengaruhi bentuk tree. Misalkan, jika urutan insertionnya 5 2 1 4 3 6 7, maka bentuk tree akan seperti berikut.

![m2-2](https://user-images.githubusercontent.com/86661387/222437403-bb31a152-14dd-4c97-ba81-c9e19615371e.png)

# Traversal Binary Search Tree

- ## Inorder Traversal

  ```c
  void __inorder(BSTNode *root) {
      if (root) {
          __inorder(root->left);
          printf("%d ", root->key);
          __inorder(root->right);
      }
  }
  ```

- ## Postorder Traversal

  ```c
  void __postorder(BSTNode *root) {
      if (root) {
          __postorder(root->left);
          __postorder(root->right);
          printf("%d ", root->key);
      }
  }
  ```

- ## Preorder Traversal

  ```c
  void __preorder(BSTNode *root) {
      if (root) {
          printf("%d ", root->key);
          __preorder(root->left);
          __preorder(root->right);
      }
  }
  ```

Misal pada Binary Search Tree berikut :

![m2-3](https://user-images.githubusercontent.com/86661387/222437416-bda83a18-e93b-4f79-8ffe-796df9115e75.png)

Hasil printout maka seperti berikut :

- Inorder : 1 2 3 4 5 6 7
- Postorder : 1 3 4 2 7 6 5
- Preorder : 5 2 1 4 3 6 7
