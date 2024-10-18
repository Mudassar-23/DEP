File compression and decompression tool using Run-Length Encoding (RLE):

File Compression and Decompression Tool (RLE) This project is a simple command-line tool for compressing and decompressing files using the Run-Length Encoding (RLE) algorithm. The program provides two functionalities:

Compress a file using RLE and save it. Decompress a file that was compressed using the RLE algorithm.

How it Works Compression (Run-Length Encoding) RLE is a simple form of data compression where consecutive elements are replaced with a single element and a count. For example, the string AAABBBCC would be compressed to A3B3C2. This technique is most effective for files with many consecutive repeated characters.

Decompression The decompression process takes a compressed file in the format produced by the compression step (e.g., A3B3C2) and expands it back to its original form (e.g., AAABBBCC).
