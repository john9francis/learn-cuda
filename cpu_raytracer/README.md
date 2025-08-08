# Ray tracer in c (cpu)

The goal of this project is to learn how a raytracer works and explore how I could parallelize it

I mean it seems like I could calculate all the rays at once... That's an easy way to parallelize it, it just makes sense.

I will be following [this tutorial](https://raytracing.github.io/books/RayTracingInOneWeekend.html) to learn how to make a raytracer, and I will be making notes on how to parallelize it.

# Running
```sh
docker build -t cpu_ray_tracer .
docker run --rm cpu_ray_tracer
```

To save output to an image:
```sh
docker run --rm cpu_ray_tracer > image.ppm
```

To do it all at once:
```sh
docker run --rm $(docker build -q .) > image.ppm
```