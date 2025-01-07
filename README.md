# Linked Lists vs Dynamic Arrays

This is a benchmark test to compare [linked lists](https://en.wikipedia.org/wiki/Linked_list) and [dynamic arrays](https://en.wikipedia.org/wiki/Dynamic_array) in general speed.

The benchmark dome involves:
- Creating the data structures
- Inserting `n` unsorted elements in a `(0..n)` range from an external file while keeping the structure sorted
- Checking the sorted structure for any errors
- Freeing all the required memory

> [!NOTE]
> Even though this test is made in fairness in mind, don't take it as gospel. There is an inherit flaw with benchmarks like these, that they can be optimized or specialized for specific cases, which can dractically change the results.

If you look at the code, you'll quickly realize both of them use very naive approaches. This is because I wanted to compare their raw speeds rather than a solution optimized for the specific problem at hand.

For the benchmarks, the following command was used:
```bash
hyperfine '<exe> <n>' --prepare 'ls -lia /dev' -N
```
(`<exe>` and `<n>` being placeholders for the respective executable and `n` number.)

With an Intel i7-11800H CPU running Arch Linux, here are the results:
| n | Dynamic Array | Linked List |
|---|---|---|
| 1 000 | 533.3 µs | 850.1 µs |
| 10 000 | 7.9 ms | 102.9 ms |
| 100 000 | 627.5 ms | 23389.0 ms | 



