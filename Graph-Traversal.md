# Graph Traversal

## Depth First Search (DFS)

Sesuai dengan namanya, DFS akan melakukan traversal sampai ke _vertex_ yang paling 'dalam'. Setiap kali sampai di suatu _vertex_ $u$, DFS akan memilih salah satu _vertex_ yang terhubung dengan vertex $u$ dan belum pernah dikunjungi sebelumnya, lalu melanjutkan penelusuran dari _vertex_ tersebut. Langkah ini terus dilakukan selama kita masih menemukan _vertex_ yang masih bisa dikunjungi. Jika sudah tidak ada, akan dilakukan _backtracking_ lalu kembali mencari _vertex_ yang bisa dikunjungi.  
Contoh pengimplementasian dalam _weighted_ graf dapat dilakukan secara iteratif seperti kode berikut:

```cpp
void dfs(vector<long> &result, long start){
    vector<bool> visited(vertex, false);
    stack<long> st;

    st.push(start);
    visited[start] = true;
    result.push_back(start);

    while(!st.empty()){
        long temp = st.top();
        st.pop();

        if(!visited[temp]){
            result.push_back(temp);
            visited[temp] = true;
        }

        for(auto it:adjList[temp]){
            if (!visited[it.first])
                st.push(it.first);
        }
    }
}
```

### Pseudocode DFS

![Pseudocode DFS](https://user-images.githubusercontent.com/86661387/230757101-66f12646-150e-4fc3-bfff-2e60ead92035.png)

### Ilustrasi DFS

![Ilustrasi DFS](https://skilled.dev/images/dfs.gif)

> Source: <https://skilled.dev/course/depth-first-search>

## Breadth First Search (BFS)

Traversal menggunakan BFS dimulai dari sebuah vertex, lalu akan mengunjungi _vertex_ yang terhubung langsung dengan _vertex_ tersebut (layer 1). Lalu, di langkah selanjutnya akan mengunjungi _vertex_ yang terhubung langsung dengan _vertex_ - _vertex_ pada layer 1 (layer 2) dan seterusnya sampai sudah tidak ada lagi _vertex_ yang bisa dikunjungi.  
Berbeda dengan DFS, pengimplementasian BFS dapat dilakukan secara iteratif dengan menggunakan bantuan `queue` seperti berikut :

```cpp
void bfs(vector<long> &result, long start){
    vector<bool> visited(vertex, false);
    queue<long> q;

    q.push(start);
    visited[start] = true;
    result.push_back(start);

    while(!q.empty()){
        long temp = q.front();
        q.pop();

        for(auto it:adjList[temp]){
            if (!visited[it.first]){
                q.push(it.first);
                visited[it.first] = true;
                result.push_back(it.first);
            }
        }
    }
}
```

### Pseudocode BFS

![Pseudocode BFS](https://user-images.githubusercontent.com/86661387/230757412-5b2ac4af-6080-4bb3-babe-6cb64c3a89d0.png)

### Ilustrasi BFS

![Ilustrasi BFS](https://skilled.dev/images/bfs.gif)

> Source: <https://skilled.dev/course/breadth-first-search>

Trivia question : pada DFS, kita melakukan penandaan pada node sebelum mengiterasi isi dari adjacency list, sedangkan pada BFS, kita melakukan penandaan di dalam iterasi. Apakah timing penempatan tanda ini berpengaruh pada algoritma-algoritma tersebut? Jika iya, apa pengaruhnya?

![Graph](https://user-images.githubusercontent.com/86661387/230756660-f44e3a38-30bd-4f93-b763-c7647fd2b92d.png)

Jika kita melakukan BFS pada graf tersebut dari vertex 1, maka vertex-vertex tiap layer adalah:

- Layer 0 : 1
- Layer 1 : 2 5
- Layer 2 : 3 4
- Layer 3 : 6

Perhatikan bahwa jumlah layer adalah jumlah dari edge minimal yang harus dilewati untuk sampai ke vertex tersebut dari vertex 1 atau biasa disebut dengan _shortest path_.
