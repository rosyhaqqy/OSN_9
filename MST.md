# Minimum Spanning Tree

***Minimum Spanning Tree*** adalah sebuah permasalahan untuk membentuk sebuah *tree* yang mengunjungi semua *vertex* yang ada dengan *weight* paling minimum.

![ilustrasi](https://user-images.githubusercontent.com/86661387/230758011-459c577d-0bba-4a86-b50f-6d6b3f5db727.png)

Terdapat 2 implementasi yang terkenal untuk mengimplementasikan Minimum Spanning Tree, yaitu Algoritma Kruskal (O($E log V$)) dan Algoritma Prim (O($(V+E) log V$)).

---

## Algoritma Prim

**Algoritma Prim membentuk MST dengan cara menambahkan *vertex* satu per satu.**
Pada setiap langkah, algoritma ini memilih *edge* dengan *weight* minimum yang menghubungkan *vertex* yang sudah ada di dalam MST dengan *vertex* yang belum ada di dalam MST.

Langkah-langkah Algoritma Prim:

1. Pilih sebuah *vertex* awal, masukkan ke dalam MST.
2. Masukkan semua *edge* yang terhubung dengan *vertex* awal ke dalam struktur data (misalnya *priority queue*).
3. Ambil *edge* dengan *weight* terkecil dari *priority queue*. Jika *vertex* tujuan *edge* tersebut belum ada dalam MST, masukkan ke MST.
4. Ulangi langkah 2–3 sampai semua *vertex* sudah masuk MST (jumlah *edge* dalam MST = V – 1).


### Implementasi

```c++
long prims(long start, vector<pair<long, pair<long, long>>> &result){
    vector<bool> inMST(vertexCount, false); // apakah suatu vertex itu sudah masuk kedalam spanning tree
    priority_queue<pair<long, pair<long, long>>,
                   vector<pair<long, pair<long, long>>>,
                   greater<pair<long, pair<long, long>>>> pq; // pq untuk menyimpan kandidat edge
    long mstWeight = 0;

    inMST[start] = true;
    for(auto edge : adjList[start]){
        pq.push({edge.second, {start, edge.first}});
    }

    while(!pq.empty() && result.size() < vertexCount-1){ // akan berjalan selama kandidatnya belum habis dan selama vertexnya masih ada yang belum masuk tree
        auto [w, uv] = pq.top(); pq.pop();
        long u = uv.first;
        long v = uv.second;

        if(inMST[v]) continue; // jika vertexnya sudah ada didalam tree

        inMST[v] = true;
        result.push_back({w,{u,v}});
        mstWeight += w;

        for(auto edge : adjList[v]){ // untuk menambahkan kandidat dari vertex yang telah ditambahkan
            if(!inMST[edge.first]){
                pq.push({edge.second,{v,edge.first}});
            }
        }
    }
    return mstWeight;
}
```

---

## Algoritma Kruskal

**Algoritma Kruskal menambahkan *edge* satu per satu sehingga menjadi Spanning Tree.**
Algoritma Kruskal merupakan pendekatan *greedy* di mana pada setiap iterasi mencari *edge* dengan *weight* terkecil untuk ditambahkan sehingga dapat membentuk Spanning Tree.

Pada Algoritma Kruskal, untuk mendapatkan Minimum Spanning Tree, berikut merupakan 4 langkah yang dilakukan:

1. Buat semua *vertex* menjadi *tree* individu (hanya berisi satu *vertex*).
2. Sort secara *non-descending* (tidak menurun) semua *edge* berdasarkan *weight*-nya.
3. Ambil *edge* dengan *weight* terkecil. Apabila terbentuk *cycle* pada *Spanning Tree*, maka lewati *edge* tersebut. Apabila tidak, tambahkan *edge* tersebut pada *Spanning Tree*.
4. Lakukan langkah ke-3 hingga terbentuk V – 1 *edge* pada *Spanning Tree*.

### Contoh

![contoh](https://s3.stackabuse.com/media/articles/graphs-in-python-minimum-spanning-trees-kruskals-algorithm-6.gif)

> Source: [https://stackabuse.com/courses/graphs-in-python-theory-and-implementation/lessons/minimum-spanning-trees-kruskals-algorithm/](https://stackabuse.com/courses/graphs-in-python-theory-and-implementation/lessons/minimum-spanning-trees-kruskals-algorithm/)

---

## *Disjoint-Set Union*

*Disjoint-Set Union* merupakan sebuah struktur data yang menyimpan sekumpulan himpunan yang tidak saling tumpang tindih (*non-overlapping sets*). Pada Algoritma Kruskal, *DSU* digunakan untuk memeriksa apakah penambahan suatu *edge* membentuk *cycle* dan untuk menggabungkan 2 *tree* menjadi satu.

### Find

```c++
long find_parent(vector<long> &parent, long v){
    if(v == parent[v]) return v;
    return find_parent(parent, parent[v]);
}
```

### Union

```c++
void union_set(vector<long> &parent, long vertex1, long vertex2){
    int parent1 = find_parent(parent, vertex1);
    int parent2 = find_parent(parent, vertex2);

    if (parent1 != parent2)
        parent[parent2] = parent1;
}
```

---

## Implementasi Kruskal

```c++
void kruskal(vector<pair<long, pair<long, long>>> &result){
    vector<long> parent;
    for(int i=0; i<vertexCount; i++) parent.push_back(i);

    sort(edgeList.begin(), edgeList.end());
    
    for(auto edge:edgeList){
        long vertex1 = edge.second.first;
        long vertex2 = edge.second.second;
        if(find_parent(parent, vertex1) != find_parent(parent, vertex2)){
            result.push_back(edge);
            union_set(parent, vertex1, vertex2);
            if(result.size() == vertexCount-1) return;
        }
    }
}
```

## 👉 Rule of thumb:

- Jika graf padat dan kamu sudah punya adjacency list → gunakan Prim’s.
- Jika graf jarang atau input berupa edge list → gunakan Kruskal’s.