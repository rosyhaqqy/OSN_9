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

[**Lanjut ke Binary Search Tree >**](<https://github.com/Algoritma-dan-Pemrograman-ITS/StrukturData/wiki/Modul-2-(Binary-Search-Tree)>)
