  <h1 align="center">BitImger</h1>
  <p align="center">A set of image processing algorithms implemented in C</p>
</div>

<br>

## Image processing options
- <b>binary</b> - Applies binary (black and white) filter to an image using [Otsu's method](https://en.wikipedia.org/wiki/Otsu%27s_method).
- <b>grayscale</b> - Applies grayscale filter to an image
- <b>blur</b> - Blurs an image.
- <b>edge</b> - Finds and accentuates edges of an image using [Sobel–Feldman operator](https://en.wikipedia.org/wiki/Sobel_operator).
- <b>sort</b> - Sorts image's pixels.
- <b>resize</b> - Scales an image while preserving the aspect ratio.
- <b>flip</b> - Flips an image.
- <b>rotate</b> - Rotates an image.

## Supported Image Types
- jpg
- png
- bmp
<p>Image encoding and decoding are handled using parts of the <a href="https://github.com/nothings/stb">stb library</a></p>


## Running locally
1) Clone the repository and navigate to it
2) Place an example image in the local folder
3) Run the following command in your terminal: `gcc *.c */*.c */*/*.c -o bitImger` ([GCC compiler](https://gcc.gnu.org/) is required)
4) Run the following command in your terminal: `bitImger.exe`


## License
[MIT](https://choosealicense.com/licenses/mit/)
