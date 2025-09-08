# Graph

# Pengenalan Graf

Graf adalah sekumpulan _vertex/node_ yang dihubungkan oleh nol atau lebih _edge_.

![Graph](https://user-images.githubusercontent.com/86661387/230756660-f44e3a38-30bd-4f93-b763-c7647fd2b92d.png)

## Terminologi

- `weight` - "berat" dari suatu _edge_. dapat juga diartikan sebagai panjang sebuah _edge_.
- `unweighted graph` - istilah dimana _edge_ pada suatu graf tidak memiliki _weight_.
- `weighted graph` - istilah dimana _edge_ pada suatu graf memiliki _weight_.
- `undirected edge` - istilah untuk menyatakan apabila sebuah edge bersifat dua arah.
- `directed edge` - istilah untuk menyatakan apabila sebuah edge bersifat satu arah.
- `path` - urutan satu atau lebih _edge_ yang dilewati untuk menghubungkan dua buah _vertex_.
- `connected` - sebuah graf dimana terdapat setidaknya satu buah _path_ untuk setiap pasang _vertex_.
- `cycle` - sebuah path yang berawal dan berakhir pada satu buah _vertex_ yang sama tanpa melewati dua buah _edge_ yang sama.
- `tree` - sebuah _undirected connected_ graf yang tidak memiliki _cycle_.
- `root` - _vertex_ dengan kedalaman ter-rendah.
- `ancestor` - himpunan _vertex_ yang dilewati dalam suatu _path_ dari _root_ ke sebuah _vertex_.
- `parent` - _ancestor_ suatu node yang memiliki kedalaman tertinggi.
- `child` - kumpulan _vertex_ yang terhubung dengan suatu edge dan bukan merupakan _ancestor_.

## Cara merepresentasikan graf

Terdapat 3 cara yang sering dipakai untuk merepresentasikan sebuah graf, yaitu

1. Adjacency Matrix

   Adjacency Matrix adalah representasi graf yang menggunakan matrix berukuran $V*V$. Pada indeks dari matrix, digunakan nilai:

   - **0** jika tidak terdapat _edge_ yang menghubungkan _vertex_ **i** dengan _vertex_ **j**.
   - **1** jika terdapat _unweighted edge_ yang menghubungkan _vertex_ **i** dengan _vertex_ **j**.
   - **weight** jika terdapat _weighted edge_ yang menghubungkan _vertex_ **i** dengan _vertex_ **j**.

   Sebagai contoh, adjacency matrix untuk graf pada contoh adalah sebagai berikut:

   ```txt
   0 1 0 0 1 0
   1 0 1 0 1 0
   0 1 0 1 0 0
   0 0 1 0 1 1
   1 1 0 1 0 0
   0 0 0 1 0 0
   ```

2. Adjacency List

   Kelemahan dari adjacency matrix adalah penggunaan memory yang menghabiskan memory sebanyak $V^2$.
   _Adjacency List_ menawarkan representasi graf yang lebih hemat dalam penggunaan memory. Ide dari perepresentasian dengan menggunakan _Adjacency List_ adalah dengan hanya menyimpan daftar dari vertex-vertex lain yang memiliki edge yang terhubung dengan suatu vertex. Implementasiannya dapat dilakukan dengan menggunakan vector seperti berikut:

   ```cpp
   vector< int > adjList[V];

   //memasukkan edge a-b
   adjList[a].push_back(b);
   adjList[b].push_back(a);
   ```

   untuk _weighted_ graf kita dapat menggunakan `pair<int,int>` sebagai isi dari _Adjacency List_ untuk menyimpan _vertex_ yang adjacent beserta weightnya.
   Berikut implementasi untuk _weighted_ graf :

   ```cpp
   vector< pair<int,int> > adjList[V];

   //memasukkan edge a-b dengan weight c
   adjList[a].push_back(make_pair(b,c));
   adjList[b].push_back(make_pair(a,c));
   ```

   penggunaan metode ini dalam merepresentasikan graf sangat direkomendasikan karena sangat efisien dalam penggunaan memori maupun kompleksitas waktu dalam melakukan traversal.

   Sebagai contoh, adjacency list untuk graf pada contoh adalah sebagai berikut:

   ```txt
   1: 2 5
   2: 1 3 5
   3: 2 4
   4: 3 5 6
   5: 1 2 4
   6: 4
   ```

3. Edge List

   Ide dari perepresentasian graf dengan metode ini adalah dengan menyimpan semua daftar _edge_ yang ada dalam suatu graf. Penyimpanan dapat dilakukan di dalam sebuah array statis maupun dinamis seperti `vector`.
   Pengimplementasiannya dapat menggunakan struct yang berisi vertex yang berada diujung _edge_ tersebut beserta _weight_ nya. Alternatif lain adalah menggunakan `pair<pair<int,int>,int>` untuk menyimpan informasi yang dibutuhkan tadi.  
   Contoh implementasinya adalah sebagai berikut:

   ```cpp
   vector< pair<pair<int,int>,int> > edgeList;

   // memasukkan edge a-b dengan weight c
   edgeList.push_back(make_pair(make_pair(a,b),c));
   ```

   Untuk _unweighted_ graf kita dapat mengganti isi dari vector menjadi `pair<int,int>`.

   Sebagai contoh, edge list untuk graf pada contoh adalah sebagai berikut:

   ```txt
   1, 2
   1, 5
   2, 3
   2, 5
   3, 4
   4, 5
   4, 6
   ```

   Metode ini sangat berguna dalam algoritma kruskal untuk mencari _Minimum Spanning Tree_ dari sebuah graf.

## Implicit Graph

Dalam beberapa kasus, kita tidak memerlukan suatu struktur data khusus untuk menyimpan suatu graf agar bisa ditelusuru ataupun dioperasikan. Kasus-kasus tersebut terjadi jika graf berbentuk _implicit graph_.

2 Bentuk umum dari implicit graph yaitu :

![Implicit Graph](https://user-images.githubusercontent.com/86661387/230756865-57ccdf28-dc36-4291-9a7b-b17dbaf1b242.png)

1. Graf dengan edge yang implisit

   - Contoh 1:

     Seperti yang kalian sering jumpai pada modul rekursi di dasar pemrograman, yaitu sebuah grid yang berisi karakter '.' ataupun '#' dimana kita tidak bisa mengunjungi grid yang berisi '#'. (Gambar A)  
      Secara tidak sadar, ini adalah sebuah graf dengan vertexnya merupakan posisi yang berisi '.' serta edgenya menghubungkan dua buah '.' yang saling bersentuhan. (Gambar B)  
      Dapat dilihat bahwa kita tidak memerlukan salah satu dari 3 teknik merepresentasikan graf seperti yang dijelaskan sebelumnya.

   - Contoh 2:

     Graf yang dibentuk berdasarkan pergerakan bidak kuda pada permainan catur. Kita dapat menganggap petak-petak pada catur sebagai vertex dari graf, serta sebuah edge menghubungkan 2 buah petak jika petak tersebut dapat dikunjungi dengan melakukan langkah bidak kuda. (Gambar C)

2. Graf dengan edge yang mengikuti suatu peraturan

   - Contoh:

     Graf dengan N vertex ([1..N]) dimana terdapat edge yang menghubungkan $i$ dan $j$ jika $(i+j)$ adalah prima. (Gambar D)
