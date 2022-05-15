  <h1 align="center">BitImger</h1>
  <p align="center">A set of image processing algorithms implemented in C</p>
</div>

<br>

## Image processing options (with source code)
- [binary](./src/filters/binary.c) - Applies binary (black and white) filter to an image using the [Otsu's method](https://en.wikipedia.org/wiki/Otsu%27s_method).
- [grayscale](./src/filters/grayscale.c) - Applies grayscale filter to an image
- [blur](./src/filters/blur.c) - Blurs an image.
- [edge](./src/filters/edge.c) - Finds and accentuates edges of an image using the [Sobel–Feldman operator](https://en.wikipedia.org/wiki/Sobel_operator).
- [sort](./src/filters/pixelSort.c) - Sorts image's pixels.
- [resize](./src/dimension_tools/resize.c) - Scales an image while preserving the aspect ratio.
- [flip](./src/dimension_tools/flip.c) - Flips an image.
- [rotate](./src/dimension_tools/rotate.c) - Rotates an image.

## Supported Image Types
- jpg
- png
- bmp
<p>Image encoding and decoding are handled using parts of the <a href="https://github.com/nothings/stb">stb library</a></p>

## License
[MIT](https://choosealicense.com/licenses/mit/)
