# Fract-ol  |  <!-- [![daviles-'s 42 fract-ol Score](https://badge42.vercel.app/api/v2/cljnk09b8001108mj13orwiyl/project/3099410)](https://github.com/JaeSeoKim/badge42) -->
>The goal of this project is to create a small fractal exploration program.

## Index
| [Project overview](#project-overview) |
[Installation & Usage](#installation--usage) |
[Fractals overview](#fractals-overview) |
[Screenshots and media](#screenshots-and-media) |
[Notes and bibliography](#notes-and-bibliography) |


## Project overview

This project was carried out using miniLibX, the graphic library of campus 42. A library with certain limitations that enhances creativity and problem solving.
The goal is for us to discover and use the mathematical notion of complex numbers, become familiar with the concept of optimization in CGI, and practice event handling.

### Main requirements:
**1. Rendering**
* Your program must offer the Julia and Mandelbrot sets.
* The mouse wheel zooms in and out and zooms almost infinitely (within from the limits of the computer).
* You should be able to create a different Julia set using the program parameters.
* A parameter will be passed through the CLI to define the type of fractal displayed.
* If a parameter is not entered, or if the parameter is invalid, the program it will display a list of available parameters and exit successfully.
* You should use at least a few colors to show the depth of each fractal.

**2. Graphic representation**
* Your program has to display the image in a window.
* The ESC key should close the window and exit the program cleanly.
* Clicking the cross in the window frame should close the window and close the program cleanly.

**3. Bonus**
* One more different fractal.
* The zoom follows the current position of the mouse.
* In addition to zoom: move with arrows.
* Make the color range change

**4. My personal touch**
* Instructions and personalized messages in every step. From the compilation to the execution of the program.
* Resolution change from the keyboard to enhance the effect of fractals.
* Changing the color set from the keyboard.
* Use of the wheel and mouse buttons to zoom.
* In Julia set, you can use choose between three ways to set the parameters.
  Right click on any part of the window.
  Press M key to enter live mode and change the values while moving mouse on screen.
  Press J to change from a list of iconic Julia sets.


## Installation & Usage

To generate an executable for this project run `make` in the root of the project directory after you've downloaded or cloned it.

`This project will only work on MacOS El Capitan/Sierra/HighSierra and even then, no promises!`

After running make to generate the fractol executable you will find the instructions to continue. 

<img width="627" alt="Run after make" src="https://github.com/Karsp/42-fract-ol/assets/32735225/7959de75-773f-4257-9a90-2315ea751c6b">

Run the program with ./fractol [fractol option]

<img width="550" alt="Select fractol" src="https://github.com/Karsp/42-fract-ol/assets/32735225/6781226c-c6e5-49f9-84e0-0699e7b58030">

When you run the program with your desired fractal, you will receive the instructions of use:

<img width="625" alt="RunningMandelbrot" src="https://github.com/Karsp/42-fract-ol/assets/32735225/3e1fafa5-5da5-4dac-9502-d3b1cc516d0b">

<img width="628" alt="Running Julia" src="https://github.com/Karsp/42-fract-ol/assets/32735225/4a952fe5-f93a-4595-bdae-f814c0306cf1">

<img width="628" alt="RunningBurning" src="https://github.com/Karsp/42-fract-ol/assets/32735225/dd10d862-c3c3-4bfc-984e-af6192fe1c02">

**Enjoy it!**


## Fractals overview

### Mandelbrot set

This notes are the result of my research for this project, looking for what is a fractal and what is the connection with Mandelbrot set.

The Mandelbrot set (and other fractals) are usually drawn so that there are lots of nice colors around a black shape, like this: 

![MandelPic1](https://github.com/Karsp/42-fract-ol/assets/32735225/4e854b0b-12a0-4433-b78c-c762d072d515)

Many people think that the Mandelbrot set is formed by those colors, or that they are part of it.

Actually the Mandelbrot set is that black shape in the middle. Everything that is outside that black shape is not part of the set. (Actually drawing just the set itself and leaving everything else blank results in a pretty boring image...). The colors in those images are not, however, completely unrelated to the set itself. 

This document tries to explain in a simple and clear manner what the Mandelbrot set is.
The first part explains it in a more mathematical way. This might be a bit difficult to understand. However, the second part approaches the set in a more practical manner, how it can be calculated with a programming language. 
The Mandelbrot set is a set of complex numbers defined in the following way:

![eqn1](https://github.com/Karsp/42-fract-ol/assets/32735225/ca557f2c-c50e-48fc-b319-be9e0893640a)


where:

![eqn2](https://github.com/Karsp/42-fract-ol/assets/32735225/a47ae709-b756-475f-9dd8-bc2466fd4d3d)


That is, the Mandelbrot set is the set of all complex numbers which fulfill the condition described above, that is, if the value of the (recursive) function Zn for the value c is not infinite when n approaches infinity, then c belongs to the set. 

We are interested in the behavior of 0 under iteration

f_c (z) = z^2 + c

Examples:

**Case 1 c = 1**

f_1 (0) = 0^2 + 1

f_1 (1) = 1^2 + 1

f_1 (2) = 2^2 + 1

f_1 (5) = 5^2 + 1

f_1 (26) = 26^2 + 1

…

**Case 2 c = -1**

f_-1 (0) = 0^2 + -1

f_-1 (-1) = -1^2 + -1

f_-1 (0) = 0^2 + -1

…


`Watch the full explanation` [here](https://www.youtube.com/watch?v=NGMRB4O922I)

What Mandelbrot set concerns is what happens to the size of these numbers (results), and by size I mean the distance from the number in the complex plane to the point 0.

So it turns out there are two option for this function:
1. The first option is that the distance from 0 of the sequence we get gets arbitrarily large. (Blows up) That means that the iterates go to infinity
2. The other thing that can be happen is that the distance (or size) is bounded. In fact you can say that it never gets larger than 2.

So if you give me a complex number c, and I start iterating zero under that function z^2 + c, either the distance of the iterates to 0 in this complex plane gets really large for all of them, or it stays close to 0, within a distance of 2 to 0.

> We can say that the definition of the Mandelbrot set says that M (belongs to Mandelbrot set) is the sets of C (complex numbers C) under iteration of 0 in the function wich result reachs case 2 holds (never gets larger than 2).

**Calculating the set**
- Scaling between pixel coordinates and complex numbers
The first thing to do when we are going to draw the Mandelbrot set in an image is to set the equivalence between pixel coordinates and complex numbers.

This means that each pixel in our image has to represent a complex number (in the complex plane, ie. the cartesian coordinate system). Then we will color that pixel according to whether it belongs to the Mandelbrot set or not.

There are basically two approaches to this:

1. We can define that the first pixel (that is, the pixel at the left upper corner) is a certain complex number and that the distance between pixels is a certain amount. For example, we could say that the first pixel represents the complex number -2+i and that the distance between pixels is 0.01 (that is, the pixel at the right of the first pixel will represent the number -1.99+i, the next pixel -1.98+i and so on).
2. We can define for all the corner pixels what complex number they represent and then just interpolate the in-between pixels when calculating the set. 

Both ways are basically the same (the values needed for one can be calculated from the other), but they represent two different approaches to the same problem.

The first approach is more like having a coordinate around which to calculate the set (a variation of this is to have the pixel at the center of the image to represent the complex number) and a zooming value (the step between pixels). To zoom to a point we only need to decrease the step value.

This approach is sometimes quite useful.

However, I personally find the second approach easier to understand and use. Just define the four corners and calculate. 

I define the area of the set using this approach:

```
MinRe = -2.0;
MaxRe = 1.0;
MinIm = -1.2;
MaxIm = MinIm+(MaxRe-MinRe)*ImageHeight/ImageWidth;
```

I define that the minimum real part of the complex numbers
(that is, the left border of the image) is -2.0 and the maximum (that is,
the right border) is 1.0. This means that the real part of the complex
numbers will go from -2.0 to 1.0.

In the same way I defined that the lower border of the image is equivalent
to the imaginary part -1.2.

Now, I could have defined the upper border of the image in the same way,
eg. setting it the 1.2. However, setting it this way would stretch the
image a bit depending on the dimensions of the image. So what I do instead
is to calculate automatically the equivalent `MaxIm` according
to the image dimensions and the real part size.

So, how to calculate the complex **values for the pixels** in between?

If the pixel at the left upper corner of the image has (pixel) coordinates
`[0, 0]` and the pixel at the lower right corner of the image has
coordinates `[ImageWidth-1, ImageHeight-1]`, then, to get the
equivalent complex number for a specific coordinate `[x, y]`
from the values set above (ie. `MinRe` etc) the formula is
the following:

```
 c_re = MinRe + x*(MaxRe-MinRe)/(ImageWidth-1);
 c_im = MaxIm - y*(MaxIm-MinIm)/(ImageHeight-1);
```

(Note that the imaginary part goes from positive to negative instead of the other way around since we consider the positive imaginary axis to be up, while the 'y' coordinate increases when going down.)

The code goes through each pixel in the image and calculates the equivalent complex number for each pixel into `c_re` and `c_im`.

**The base code**

So we get the base code for our Mandelbrot drawing program (here in C++, but easily programmable in almost any language):

double MinRe = -2.0;
double MaxRe = 1.0;
double MinIm = -1.2;
double MaxIm = MinIm+(MaxRe-MinRe)*ImageHeight/ImageWidth;
double Re_factor = (MaxRe-MinRe)/(ImageWidth-1);
double Im_factor = (MaxIm-MinIm)/(ImageHeight-1);

for(unsigned y=0; y<ImageHeight; ++y)
{
    double c_im = MaxIm - y*Im_factor;
    for(unsigned x=0; x<ImageWidth; ++x)
    {
        double c_re = MinRe + x*Re_factor;

        // Calculate whether c belongs to the Mandelbrot set or
        // not and draw a pixel at coordinates (x,y) accordingly
    }
}

The code goes through each pixel in the image and calculates the equivalent complex number for each pixel into c_re and c_im.

Now we only have to calculate the part left out in the place of the comment in the above code. 

**Calculating the Mandelbrot function**

Now to determinate if it numbers belongs to M set, we just have to calculate Zn with c being in this case `c_re + c_im * i`. (being **i** the number of iterations we will check).

First we have to decide how many times we want to iterate the function
(as described earlier) and then loop that many times calculating the new
value of Zn at each loop. It could look like this:

```
for(unsigned n=0; n<MaxIterations; ++n)
        {
            if(/* Absolute value of Z */ > 2)
            {
                isInside = false;
                break;
            }
            /* Z = Z2 + c */
        }
        if(isInside) { putpixel(x, y); }
```

This iterates `MaxIterations` times, and in each iteration it
looks whether Z is greater than 2. If it is, it sets `isInside`
to false (as we saw earlier, if the value of Z ever goes farther away than
2 from the origin, c doesn't belong to the set).

We are now only missing the absolute value of Z and the function
`Z2+c`.

The absolute value is easy. The absolute value of a complex number is
defined as its distance from the origin, that is,
`sqrt(Zr2+Zi2)`

Note: The if-statement above would have the following form:

```
            if(sqrt(Z_re*Z_re + Z_im*Z_im) > 2)

```

However, from mathematics we know that we can simplify that to:

```
            if(Z_re*Z_re + Z_im*Z_im > 4)

```

which is a lot faster to calculate since we don't need the square root
anymore.

And what about `Z2+c`?

The addition of two complex numbers is simple. Just add the real parts
and the imaginary parts together. However, complex number multiplication
is not that easy. We can deduce mathematically how the multiplication can
be calculated:

![eqn3](https://github.com/Karsp/42-fract-ol/assets/32735225/97ab9c12-d3ac-4eca-9ffb-11d25a671301)

So we see that in the result of the multiplication the real part is
a2-b2 and the imaginary part is 2*a*b.

Knowing this we can write the `Z2+c` part of the
code:

```
            z_im = 2 * z_re * z_im + c_im;
            z_re = (z_re * z_re) - (z_im * z_im) + c_re;

```

**Coloring the image**

How do we get those fancy colors around the set?

In fact, there are many ways of getting colors outside (and even inside) the set.

The classical way and also perhaps the most useful way of coloring the exterior of the set is to use the value of 'n' after the inner loop has ended. That is, using the number of iterations that was needed for Z to get larger than 2.

In practice, after the inner loop has ended (the one with n being the loop index) we get a value for n that is between 0 and the maximum number of iterations. If n is the maximum number of iterations then we know that Z did not get larger than 2 and the current c is (most probably) part of the set and we can color that with black (or whatever color we want).

If, however, n is smaller than the maximum number of iterations then we know that this c does not belong to the set and then we can map the value of n to a color and draw the point with that color.

In this example we map n to a color so that from 0 to MaxIterations/2-1 the color goes from black to red and from MaxIterations/2 to MaxIterations-1 the color goes from red to white, we get the following image: 

![pic3](https://github.com/Karsp/42-fract-ol/assets/32735225/eb2fab0c-b76f-4286-bc63-8b4cc24bb876)

The colors are not only visually appealing, but they also give us a lot of extra information that didn't show up in the colorless version. The shapes formed by the colors are not coincidence, but they are closely related to the set itself.

The Mandelbrot set has the property that for a value which is close to the border of the set it will take longer (that is, more iterations) to escape to infinity than for a value which is farther away from the border of the set. This means that our colors are actually saying to us where the border of the set is: The brighter the color, the closer the border of the set is. 

***

### Julia set

One cannot study the Mandelbrot set without hearing about the Julia set as well. Almost always when the Mandelbrot set is discussed or explained, the Julia set is also mentioned. This document is no exception.

So what is the Julia set and what is it relation to the Mandelbrot set? 

Julia sets can be quite pretty, but their connection to the Mandelbrot set is not clear.

The first connection is the mathematical definition of the set. It's almost identical to the Mandelbrot set: 

![Juliaeqn4](https://github.com/Karsp/42-fract-ol/assets/32735225/9cc20131-42aa-41a1-8f2f-aad5873fcea5)

where: 

![Juliaeqn5](https://github.com/Karsp/42-fract-ol/assets/32735225/4b998784-f4f3-4bae-b7fa-89f494064988)

The only difference to the Mandelbrot set is that the generic Zn function is not "Zn+1=Zn2+c", but "Zn+1=Zn2+K", where K is some chosen (constant) complex number.

This means that although there is only one Mandelbrot set, there are many Julia sets (actually an infinite amount), one for each possible K (ie. one for each complex number).

In my case, I took the values of the positions in x and y of the plane, and added to the function fo Mandelbrot set. It looks like this: 

```
            z_im = 2 * z_re * z_im + k_x;
            z_re = z_re = (z_re * z_re) - (z_im * z_im) + k_y;
```

The value of K has a quite interesting relation with the Mandelbrot set:

- If K is inside the Mandelbrot set, then the Julia set for K will be
connected. If K is outside the Mandelbrot set, then the Julia set for K will
be disconnected (that is, it will have at least two disconnected "islands").
- If we choose a K from inside the Mandelbrot set, its location inside
the set will have a radical influence in the shape of the respective Julia
set. The closer K is to the border of the Mandelbrot set, the "thinner"
an more "whirly" the correspondent Julia set will be. If we choose a K
farther away from the border, the respective Julia set will be "thicker".
- If we choose a K which is very close to the border of the Mandelbrot
set, there will also be a close relation between the shape of the Julia
set and the shape of the border of the Mandelbrot set at that place. Zooming
in the Mandelbrot set around K will bring up shapes that look like the
Julia set for K.

For these reasons it is said that the Mandelbrot set is a "map" of all
the Julia sets.

***

### Burning ship 

Function

![Burningshipeq1](https://github.com/Karsp/42-fract-ol/assets/32735225/c3c75699-8c16-4329-8558-dc726e714d5d)

The Burning Ship fractal, is generated by iterating the function in the complex plane C which will either escape or remain bounded. The difference between this calculation and that for the Mandelbrot set is that the real and imaginary components are set to their respective absolute values before squaring at each iteration.

I used the math function fabs() to get the absolut value of both components. It looks like this:

```
				z_im = fabs(z_im);
				z_re = fabs(z_re);
				z_im = 2 * z_re * z_im + c_im;
				z_re = (z_re * z_re) - (z_im * z_im) + c_re;
```

Note that the typical images of the Burning Ship fractal display the ship upright: the original fractal, and that produced by the code I’ve used, is inverted along the x-axis.
So in order that all the moving and zooming functions works, I had to modify some values on them and create new specific functions.

**This was one of the chosen fractals for bonus, check out on the bibliography for more examples**



## Screenshots and media

**1 Mandelbrot Set**
* Changing color 
![Mandelbrot changing colors](https://github.com/Karsp/42-fract-ol/assets/32735225/40b182fa-eb1d-4cfb-9578-0a482acd8d1a)

* Changing resolution
![Mandelbrot changeing resolution](https://github.com/Karsp/42-fract-ol/assets/32735225/76763932-4257-4346-8205-2ad8bdd23510)

* Dive in some random points
![Mandelbrot zoom 2](https://github.com/Karsp/42-fract-ol/assets/32735225/e36e495a-915c-4e69-bf01-101b4870aa02)

***

**2 Julia Set**
* Changing from recomended fractal sets 
![Fractol_media_01](https://github.com/Karsp/42-fract-ol/assets/32735225/24160870-685f-48cc-8ebc-54ab7acea899)

* Changing color and resolution
![Fractol_media_02](https://github.com/Karsp/42-fract-ol/assets/32735225/2d5a4d4a-d133-42c8-9219-8d1e318b1110)

* Enter live mode of fractal generation
![Fractol_media_03](https://github.com/Karsp/42-fract-ol/assets/32735225/f1b4676b-545f-432c-a7da-b88a26f12bd5)

* Dive in some random points
![Julia zoom 1](https://github.com/Karsp/42-fract-ol/assets/32735225/3201b26e-2ba6-4e4b-9802-ab1a254cc747)

***

**3 Burn Ship Set**
* Dive in some random points
![Bunrshipzoomin1](https://github.com/Karsp/42-fract-ol/assets/32735225/61a6d914-228c-4418-8398-5b63b43d06ba)

* Zommin and change resolution
![Burningship zommresolution](https://github.com/Karsp/42-fract-ol/assets/32735225/36f7e49f-ec1a-4f4b-bbec-b090d1a0acd0)



## Notes and bibliography

**MiniLibX**
- [MiniLibX - 42 Docs](https://harm-smits.github.io/42docs/libs/minilibx.html)
- [More documentation of MiniLibX](https://qst0.github.io/ft_libgfx/#minilibx)
- [Some examples with MLX](https://github.com/terry-yes/mlx_example)
- [Image tutorials with MLX](https://github.com/keuhdall/images_example)

MiniLibx notes
Registering events with minilibx's hooks
int	mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int	mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int	mlx_expose_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int	mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);
int	mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);

The mlx_loop_hook is one hook that is triggered when there's no event processed. It is especially useful to draw things continuously on the screen,

mlx_destroy_display DONT EXIST

- [Encoding and decoding colors](https://harm-smits.github.io/42docs/libs/minilibx/colors.html)
We can use two methods to encode and decode colors:

**BitShifting**
**char/int conversion**
BitShifting
Since each byte contains 2^8 = 256 values (1 byte = 8 bits), and RGB values range from 0 to 255, we can perfectly fit a integer (as an int is 4 bytes). In order to set the values programatically we use bitshifting. Let’s create a function which does precisely that for us, shall we?


**Mandelbrot set**
- [Conjunto de Mandelbrot - Wikipedia](https://es.wikipedia.org/wiki/Conjunto_de_Mandelbrot)
- [Video - The Mandelbrot Set - Numberphile](https://www.youtube.com/watch?v=oCkQ7WK7vuY&list=PLt5AfwLFPxWJ8GCgpFo5_OSyfl7j0nOiu&index=11)
- [Complete explanation of Mandelbrot set](http://warp.povusers.org/Mandelbrot/)

**Julia set**
- [Understanding Julia and Mandelbrot Sets - Karl Sims ](https://www.karlsims.com/julia.html)
- [Example parameters of interesting Julia sets](http://paulbourke.net/fractals/juliaset/)
- [Video - Filled with Julia Set - Numberphile](https://www.youtube.com/watch?v=oCkQ7WK7vuY&list=PLt5AfwLFPxWJ8GCgpFo5_OSyfl7j0nOiu&index=11)

**Burnin Ship**
- [Burning ship fractal by Paul Bourke](https://paulbourke.net/fractals/burnship/)
- [Fractal del barco en llamas - Wikiedia](https://es.wikipedia.org/wiki/Fractal_del_barco_en_llamas)

**Extras and misc**
- [Smooth Zoom - stackoverflow](https://stackoverflow.com/questions/41796832/smooth-zoom-with-mouse-in-mandelbrot-set-c)
- [Interesting coloring approach](https://github.com/vkazanov/fractals-in-c)

**Examples bonus**
- [Lot of fractals to choose by Paul Bourke](https://paulbourke.net/fractals/)
- [Hypercomplex Fractals](http://bugman123.com/Hypercomplex/)
