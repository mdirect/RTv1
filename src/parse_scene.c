#include "rt.h"
#include <fcntl.h>

#define SPHERE 1
#define CYLINDER 2
#define CONE 3
#define PLANE 4




int	ft_fast_pow(int base, int pow)
{
	int res;

	res = 1;
	while (pow)
	{
		if (pow & 1)
			res *= base;
		base *= base;
		pow >>= 1;
	}
	return (res);
}

double ft_atoi_d(const char *str)
{
	int		first;
	int		second;
	double	result;
	char	*tmp;
	int		k;


	tmp = (char *)str;
	first = ft_atoi(tmp);
	while (*tmp && *tmp != '.' && *tmp != ',')
		tmp++;
	if (*tmp == ',')
		return ((double)first);
	else
		tmp++;
	second = ft_atoi(tmp);
	k = 0;
	while (*tmp && ft_isdigit(*tmp))
	{
		k++;
		tmp++;
	}
	if (second == 0)
		result = (double)first;
	else
		result = (double)(first*ft_fast_pow(10, k) + second) / ft_fast_pow(10, k);
	return (result);
}

t_point parse_point(char *str)
{
	char *tmp;
	t_point point;

	point.x = 0.0;
	point.y = 0.0;
	point.z = 0.0;
	tmp = str;
	while (*tmp && (ft_isspace(*tmp)))
		tmp++;
	point.x = ft_atoi_d(tmp);
	while (*tmp && (ft_isspace(*tmp) || ft_isdigit(*tmp) || *tmp == '.' ||
				*tmp == '-' || *tmp == '+'))
		tmp++;
	if (*tmp == ',')
		tmp++;
	else
	{
		ft_putstr("Error: something wrong with the point.x\n");
		exit(1);
	}
	point.y = ft_atoi_d(tmp);
	printf("%.2f\n", point.y);
	printf("|%s|\n", tmp);


	while (*tmp && (ft_isspace(*tmp) || ft_isdigit(*tmp) || *tmp == '.' ||
				*tmp == '-' || *tmp == '+'))
		tmp++;

	printf("|%s|\n", tmp);
	if (*tmp == ',')
		tmp++;
	else
	{
		ft_putstr("Error: something wrong with the point.y\n");
		exit(1);
	}
	point.z = ft_atoi_d(tmp);
	printf("%.2f\n", point.z);
	return(point);
}

int terminate(char *error, char **buf, int fd)
{
	ft_strdel(buf);
	ft_putstr(error);
	close(fd);
	exit(1);
}

void check_bg_color(t_point *color)
{
	if (color->x < 0.0)
		color->x = 0.0;
	if (color->y < 0.0)
		color->y = 0.0;
	if (color->z < 0.0)
		color->z = 0.0;
	if (color->x > 255.0)
		color->x = 255.0;
	if (color->y > 255.0)
		color->y = 255.0;
	if (color->z > 255.0)
		color->z = 255.0;
}

int read_light_params(char *buf, t_scene *scene)
{
	int light_type;
	double intens;
	char *tmp;

	tmp = buf;
	light_type = ft_atoi(tmp);
	if (light_type < 3 && light_type >= 0)
	{
		while (*tmp && (ft_isdigit(*tmp) || ft_isspace(*tmp)))
			tmp++;
		if (*tmp == ';')
			intens = ft_atoi_d(tmp + 1);
		else
			return (1); //think about terminate()
		tmp++;
		while (*tmp && (ft_isdigit(*tmp) || ft_isspace(*tmp) || *tmp == '.'))
			tmp++;
		if (*tmp == ';')
			tmp++;
		else
			return (1); //think about terminate()
		scene->light[light_type] = make_light(light_type, intens, parse_point(tmp));


		return (0);
	}
	return (1);	
}

int move_pointer_point(char **p)
{
	char *tmp;

	tmp = *p;
	while (*tmp && (ft_isdigit(*tmp) || ft_isspace(*tmp) || *tmp == ',' || *tmp == '.'
				|| *tmp == '-' || *tmp == '+'))
			tmp++;
	if (*tmp == ';')
	{
		tmp++;
		*p = tmp;
		return (0);
	}
	return (1);
}

int move_pointer_num(char **p)
{
	char *tmp;

	tmp = *p;
	while (*tmp && (ft_isdigit(*tmp) || ft_isspace(*tmp) || *tmp == '.'))
			tmp++;
	if (*tmp == ';')
	{
		tmp++;
		*p = tmp;
		return (0);
	}
	return (1);
}

int read_object(int type, char *buf, t_scene *scene, int i)
{
	char *tmp;
	t_point line;

	tmp = buf;
	ft_bzero(&scene->obj[i], sizeof(scene->obj[i]));
	scene->obj[i].type = type;
	if (type == SPHERE)
	{
		scene->obj[i].c = parse_point(tmp);
		if (move_pointer_point(&tmp))
			return (1);
		scene->obj[i].r = ft_atoi_d(tmp);
		if (move_pointer_num(&tmp))
			return (1);
		scene->obj[i].color = parse_point(tmp);
		if (move_pointer_point(&tmp))
			return (1);
		scene->obj[i].specular = ft_atoi_d(tmp);
		if (move_pointer_num(&tmp))
			return (1);
		scene->obj[i].mirror = ft_atoi_d(tmp);
	}
	if (type == CYLINDER)
	{
		scene->obj[i].c = parse_point(tmp);
		if (move_pointer_point(&tmp))
			return (1);
		scene->obj[i].r = ft_atoi_d(tmp);
		if (move_pointer_num(&tmp))
			return (1);
		line = parse_point(tmp);
		scene->obj[i].l = multi(1 / modul(line), line);
		if (move_pointer_point(&tmp))
			return (1);
		scene->obj[i].color = parse_point(tmp);
		if (move_pointer_point(&tmp))
			return (1);
		scene->obj[i].specular = ft_atoi_d(tmp);
		if (move_pointer_num(&tmp))
			return (1);
		scene->obj[i].mirror = ft_atoi_d(tmp);
	}
	if (type == CONE)
	{
		scene->obj[i].c = parse_point(tmp);
		if (move_pointer_point(&tmp))
			return (1);
		line = parse_point(tmp);
		scene->obj[i].l = multi(1 / modul(line), line);
		if (move_pointer_point(&tmp))
			return (1);
		scene->obj[i].angle = ft_atoi_d(tmp);
		if (move_pointer_num(&tmp))
			return (1);
		scene->obj[i].color = parse_point(tmp);
		if (move_pointer_point(&tmp))
			return (1);
		scene->obj[i].specular = ft_atoi_d(tmp);
		if (move_pointer_num(&tmp))
			return (1);
		scene->obj[i].mirror = ft_atoi_d(tmp);		
	}
	if (type == PLANE)
	{
		scene->obj[i].c = parse_point(tmp);
		if (move_pointer_point(&tmp))
			return (1);
		line = parse_point(tmp);
		scene->obj[i].l = multi(1 / modul(line), line);
		if (move_pointer_point(&tmp))
			return (1);
		scene->obj[i].color = parse_point(tmp);
		if (move_pointer_point(&tmp))
			return (1);
		scene->obj[i].specular = ft_atoi_d(tmp);
		if (move_pointer_num(&tmp))
			return (1);
		scene->obj[i].mirror = ft_atoi_d(tmp);	
	}
	return (0);
}


void print_structure(t_scene *scene)
{
	printf("bg_color: (%f, %f, %f)\n", scene->bg_color.x, scene->bg_color.y, scene->bg_color.z);
	printf("o: (%f, %f, %f)\n", scene->o.x, scene->o.y, scene->o.z);
	printf("angle: (%f, %f, %f)\n", scene->angle.x, scene->angle.y, scene->angle.z);
	for (int i = 0; i < 3; i++)
	{
		printf("light[%d]: type %d, intens %f, (%f, %f, %f)\n", i,scene->light[i].type, scene->light[i].intens,
				scene->light[i].c.x, scene->light[i].c.y, scene->light[i].c.z);
	}
	for (int i = 0; i < OBJ_C; i++)
	{
		printf("type %d, center (%.2f, %.2f, %.2f), r %f, color (%.2f, %.2f, %.2f), sp %.2f, mir %.2f\n\n",
			scene->obj[i].type, scene->obj[i].c.x, scene->obj[i].c.y, scene->obj[i].c.z,
			scene->obj[i].r, scene->obj[i].color.x, scene->obj[i].color.y, scene->obj[i].color.z,
			scene->obj[i].specular, scene->obj[i].mirror);
	}
}

int		read_scene(char *filename, t_scene *scene)
{
	t_list *lines;
	t_list *tmp;

	scene->light_quant = 0;
	scene->obj_quant = 0;
	read_lines_from_file(&lines, filename, scene);
	scene->light = (t_point *)ft_memalloc(sizeof(t_point) * scene->light_quant);
	scene->obj = (t_object *)ft_memalloc(sizeof(t_object) * scene->obj_quant);
	// tmp = lines;
	// while (lines->line)
	// {
	// 	if (ft_strcmp_head(lines->line, "bg_color:"))
	// 		scene->bg_color = parse_point(lines->line + 9);
	// 	else if (ft_strcmp_head(lines->line, "o:"))
	// 		scene->o = parse_point(lines->line + 2);
	// 	else if (ft_strcmp_head(lines->line, "angle:"))
	// 		scene->angle = parse_point(lines->line + 6);
	// 	else if (ft_strcmp_head(lines->line, "light:"))
	// 	{
	// 		if (read_light_params(lines->line + 6, scene))
	// 			terminate("Error: in light params\n", &lines->line, fd);		
	// 	}
	// 	else if (ft_strcmp_head(buf, "sphere:"))
	// 	{
	// 		if (read_object(SPHERE, buf + 7, scene, obj))
	// 			terminate("Error: in sphere\n", &buf, fd);
	// 		obj++;
	// 	}
	// 	else if (ft_strcmp_head(buf, "cylinder:"))
	// 	{
	// 		if (obj >= OBJ_C || read_object(CYLINDER, buf + 9, scene, obj))
	// 			terminate("Error: in sphere\n", &buf, fd);
	// 		obj++;
	// 	}
	// 	else if (ft_strcmp_head(buf, "cone:"))
	// 	{
	// 		if (obj >= OBJ_C || read_object(CONE, buf + 5, scene, obj))
	// 			terminate("Error: in sphere\n", &buf, fd);
	// 		obj++;
	// 	}
	// 	else if (ft_strcmp_head(buf, "plane:"))
	// 	{
	// 		if (obj >= OBJ_C || read_object(PLANE, buf + 6, scene, obj))
	// 			terminate("Error: in sphere\n", &buf, fd);
	// 		obj++;
	// 	}
	// 	else
	// 		terminate("Error: check your scene parameters.\n", &buf, fd);		
	// }
	// close(fd);
	// print_structure(scene);
	// write(1, "ok\n", 3);
	return (0);

}



