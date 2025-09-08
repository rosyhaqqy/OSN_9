# Shortest Path

**_Shortest Path_** adalah sebuah permasalahan untuk mencari _path_ terdekat (memiliki _weight_ minimal) antara 2 _vertex_ dalam satu graf. Terdapat beberapa algoritma untuk menyelesaikan permasalahan tersebut. Di bawah ini adalah tabel yang berisi algoritma yang digunakan untuk menyelesaikan permasalahan _Single Source Shortest Path_:

| **Algoritma**              | **Kompleksitas Waktu** |
| -------------------------- | ---------------------- |
| Breadth First Search       | O( $E+V$ )             |
| Dijkstra (dengan _list_)   | O( $V^2$ )             |
| Dijkstra (dengan _pqueue_) | O( $(E+V)log V$ )      |
| Bellman-Ford               | O( $VE$ )              |

## Kasus: Unweighted Graph

Pada _unweighted graph_, permasalahan shortest path dapat dilakukan menggunakan BFS (_Breadth First Search_) seperti biasa.

## Kasus: Weighted Graph

Karena terdapat _weight_ pada tiap-tiap _edge_, menggunakan BFS saja tidak akan mendapatkan hasil yang optimal, dan perlu menggunakan algoritma lain seperti Dijkstra atau Bellman-Ford. Modul ini hanya akan membahas Algoritma Dijkstra.

## Algoritma Dijkstra

Algoritma Dijkstra sendiri mempunyai banyak variasi, tapi yang paling umum adalah untuk mencari shortest path dari source vertex ke semua vertex lainnya.

### Langkah-langkah

1. Set semua jarak vertex dengan infinity (dapat digantikan dengan nilai yang sangat besar atau nilai yang tidak akan terpakai) kecuali jarak dari source yang akan di-set 0.

2. Push vertex source ke min-priority queue (priority queue dengan pengurutan dari kecil ke besar) dengan format (distance, vertex), untuk pembanding dari min-priority queue akan menggunakan distance dari vertex.

3. Pop vertex dengan distance yang paling minimum dari priority queue

4. Update distance dari vertex yang terhubung ke vertex yang telah di-pop (vertex dari hasil langkah ke-3) dengan case “distance vertex yang sekarang + edge weight < next vertex distance”, lalu push vertex tersebut.

5. Apabila hasil dari pop vertex tersebut telah di visit sebelumnya, maka lakukan continue.

6. Lakukan langkah ke-3 sampai ke-5 hingga priority queue kosong.

### Contoh

Cari shortest path dari vertex A ke semua vertex lainnya.

![contoh graf](https://user-images.githubusercontent.com/86661387/230757697-d730e60d-c5ce-4581-bb94-de754d8c99a1.png)

---

Inisial:

![inisial](https://user-images.githubusercontent.com/86661387/230757713-1ee56618-e7b8-4953-85f8-a3db0a49ec88.png)

Step 1:

![step 1](https://user-images.githubusercontent.com/86661387/230757720-7d8a9165-1e35-4a06-ab24-f809fd4d8874.png)

Step 2:

![step 2](https://user-images.githubusercontent.com/86661387/230757722-d8deea32-08c8-4d84-bc66-63e637acf9d6.png)

Step 3:

![step 3](https://user-images.githubusercontent.com/86661387/230757727-d9c8814f-863f-411f-b09b-435d0174cab3.png)

Step 4:

![step 4](https://user-images.githubusercontent.com/86661387/230757729-7840f943-ec6e-4dc2-b421-b9cbb7870443.png)

Step 5:

![step 5](https://user-images.githubusercontent.com/86661387/230757732-8273bc3b-5096-4552-8889-de398837613f.png)

### Implementasi

```C++
void dijkstra(vector<long> &result, long start){
    vector<bool> visited(vertexCount, false);
    priority_queue <pair<long, long>,
                    vector <pair<long, long>>,
                    greater <pair<long, long>> > pq;
    result = vector<long>(vertexCount, LONG_MAX);

    pq.push(make_pair(0, start));
    result[start] = 0;
    /*
    weight dari sebuah edge diletakkan pada element pertama dari pair, sehingga priority queue akan memprioritaskan edge berdasarkan weight dari edge
    */

    while(!pq.empty()){
        auto temp = pq.top();
        pq.pop();

        if(visited[temp.second]) continue;

        visited[temp.second] = true;

        for(auto vertex:adjList[temp.second]){
            long nextVertex = vertex.first;
            long weight = vertex.second;

            if(temp.first + weight < result[nextVertex]) {
                result[nextVertex] = temp.first + weight;
                pq.push(make_pair(result[nextVertex], nextVertex));
            }
        }
    }
}
```
