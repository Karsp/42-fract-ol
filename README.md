# Fract-ol  |  <!-- [![daviles-'s 42 fract-ol Score](https://badge42.vercel.app/api/v2/cljnk09b8001108mj13orwiyl/project/3099410)](https://github.com/JaeSeoKim/badge42) -->
>The goal of this project is to create a small fractal exploration program.

## Index
[Project overview](#project-overview)
[Screenshots and media](#screenshots-and-media)
[Fractals overview]
[Notes and tips to build this project]


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

## Screenshots and media
** 1 Mandelbrot Set
* Changing color 
![Mandelbrot changing colors](https://github.com/Karsp/42-fract-ol/assets/32735225/40b182fa-eb1d-4cfb-9578-0a482acd8d1a)

* Changing resolution
![Mandelbrot changeing resolution](https://github.com/Karsp/42-fract-ol/assets/32735225/76763932-4257-4346-8205-2ad8bdd23510)

* Dive in some random points
![Mandelbrot zoom 2](https://github.com/Karsp/42-fract-ol/assets/32735225/e36e495a-915c-4e69-bf01-101b4870aa02)

** 2 Julia Set
* Changing from recomended fractal sets 
![Fractol_media_01](https://github.com/Karsp/42-fract-ol/assets/32735225/24160870-685f-48cc-8ebc-54ab7acea899)

* Changing color and resolution
![Fractol_media_02](https://github.com/Karsp/42-fract-ol/assets/32735225/2d5a4d4a-d133-42c8-9219-8d1e318b1110)

* Enter live mode of fractal generation
![Fractol_media_03](https://github.com/Karsp/42-fract-ol/assets/32735225/f1b4676b-545f-432c-a7da-b88a26f12bd5)

* Dive in some random points
![Julia zoom 2](https://github.com/Karsp/42-fract-ol/assets/32735225/7c5bf72e-c953-4fc7-bd07-9557f1140661)


** 3 Burn Ship Set
* Dive in some random points
![Bunrshipzoomin1](https://github.com/Karsp/42-fract-ol/assets/32735225/61a6d914-228c-4418-8398-5b63b43d06ba)

* Zommin and change resolution
![Burningship zommresolution](https://github.com/Karsp/42-fract-ol/assets/32735225/36f7e49f-ec1a-4f4b-bbec-b090d1a0acd0)


## Fractals overview

### Mandelbrot set

This sumary notes are the result of my research for this project, looking for what is a fractal and what is the connection with Mandelbrot set.

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


For a clearer explanation, go [here](https://www.youtube.com/watch?v=NGMRB4O922I)

What Mandelbrot set concerns is what happens to the size of these numbers (results), and by size I mean the distance from the number in the complex plane to the point 0.

So it turns out there are two option for this function:
1. The first option is that the distance from 0 of the sequence we get gets arbitrarily large. (Blows up) That means that the iterates go to infinity
2. The other thing that can be happen is that the distance (or size) is bounded. In fact you can say that it never gets larger than 2.

So if you give me a complex number c, and I start iterating zero under that function z^2 + c, either the distance of the iterates to 0 in this complex plane gets really large for all of them, or it stays close to 0, within a distance of 2 to 0.

> We can say that the definition of the Mandelbrot set says that M (belongs to Mandelbrot set) is the sets of C (complex numbers C) under iteration of 0 in the function wich result reachs case 2 holds (never gets larger than 2).

In other words, we need to know if absolute value of z is greater than 2.
The absolute value of a complex number is defined as its distance from the origin, that is, sqrt(Zr2+Zi2)
