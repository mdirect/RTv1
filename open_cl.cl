__kernel void draw(__global int *pixel, float shift_x, float shift_y, float zoom,
    int type, float j_re, float j_im, int max_i, float color)
{
	int		gid = get_global_id(0);
	float	        c_re;
	float	        c_im;
	float	        z_re;
	float	        z_im;
	int		        i;
	unsigned int    r;
	unsigned int	g;
	unsigned int	b;
	float	        t;

	c_im = shift_y + (float)(gid / 1001) / zoom;
	c_re = shift_x + (float)(gid % 1001) / zoom;
	z_re = c_re;
	z_im = c_im;
	i = 0;
	while (z_re * z_re + z_im * z_im <= 4 && i < max_i)
	{
		if (type == 1)
		{
		    t = z_re * z_re - z_im * z_im + j_re;
			z_im = 2.0 * z_re * z_im + j_im;
			z_re = t;
		}
		else if (type == 2)
		{
			t = z_re * z_re - z_im * z_im + c_re;
			z_im = 2.0 * z_re * z_im + c_im;
			z_re = t;
		}				
		else if (type == 3)
		{
			t = z_re * z_re * z_re - 3 * z_re * z_im * z_im + c_re;
			z_im = 3 * z_re * z_re * z_im - z_im * z_im * z_im + c_im;
			z_re = t;
		}
		else if (type == 4)
		{
			t = z_re * z_re * z_re * z_re - 6 * z_re * z_re * z_im * z_im + z_im * z_im * z_im * z_im + c_re;
			z_im = 4 * z_re * z_re * z_re * z_im - 4 * z_re * z_im * z_im * z_im + c_im;
			z_re = t;
		}
		else if (type == 5)
		{
			t = z_re * z_re * z_re * z_re * z_re - 10 * z_re * z_re * z_re * z_im * z_im + 5 * z_re * z_im * z_im * z_im * z_im + c_re;
			z_im = 5 * z_re * z_re * z_re * z_re * z_im - 10 * z_re * z_re * z_im * z_im * z_im + z_im * z_im * z_im * z_im * z_im + c_im;
			z_re = t;
		}
		else if (type == 6)
		{
			t = fabs(z_re * z_re - z_im * z_im) + c_re;
			z_im = 2.0 * z_re * z_im + c_im;
			z_re = t;
		}
		else if (type == 7)
		{
			t = z_re * z_re - z_im * z_im + c_re;
			z_im = 2.0 * fabs(z_re * z_im) + c_im;
			z_re = t;
		}
		else if (type == 8)
		{
			t = z_re * z_re - z_im * z_im + c_re;
			z_im = -2.0 * z_re * z_im + c_im;
			z_re = t;
		}
		i++;
	}
	t = fabs((float)i / (float)max_i - color);
	r = (unsigned int)(9 * (1 - t) * t * t * t * 255);
	g = (unsigned int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (unsigned int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	pixel[gid] = ((r << (unsigned)16) | (g << (unsigned)8) | b);
}

