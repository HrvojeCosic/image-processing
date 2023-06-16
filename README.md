<p align="center">Image processing library</p>
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

## Setup
note: on Windows, follow first two steps and compile all the .c files manually
1) Clone the repository and navigate to it
2) Place an example image in the local folder
3) Run the `make deps` command to install necessary dependencies
4) Run the `make` command

## License
[MIT](https://choosealicense.com/licenses/mit/)
