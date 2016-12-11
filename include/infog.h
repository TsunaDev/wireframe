/*
** infog.h for infograph in /home/tsuna/Epitech/projects/Infograph
** 
** Made by Martin Van Elslande
** Login   <martin.van-elslande@epitech.eu>
** 
** Started on  Thu Nov 10 11:45:14 2016 Martin Van Elslande
** Last update Sun Dec 11 19:30:57 2016 Martin Van Elslande
*/

#ifndef			MY_INFOG_
# define		MY_INFOG_

# include               <math.h>
# include               <SFML/Graphics/RenderWindow.h>
# include               <SFML/Graphics/Texture.h>
# include               <SFML/Graphics/Sprite.h>
# include		<SFML/Audio.h>
# include		<fcntl.h>
# include      		<unistd.h>
# include               <stdlib.h>

# define		SCREEN_WIDTH	1920
# define		SCREEN_HEIGHT	1080

typedef	struct		s_my_framebuffer
{
  sfUint8		*pixels;
  int			width;
  int			height;
}			t_my_framebuffer;

void			my_draw_line(t_my_framebuffer *framebuffer,
				     sfVector2i from, sfVector2i to,
				     sfColor color);
sfRenderWindow		*window_open(int width, int height);
t_my_framebuffer	*my_framebuffer_create(int width, int height);
void			window_loop(sfRenderWindow *window, sfSprite *sprite);
void			get_coordinates(char **av, int ***coordinates,
					int **size);
void			my_put_pixel(t_my_framebuffer *framebuffer, int x,
				     int y, sfColor color);
int			my_getnbr(char *str);
sfColor			coloration(float z);
sfVector3f              create_3dvector(int *coordinates, int x, int size);
sfVector2i              vector_creator(int x, int y);
sfVector2i              my_parallel_projection(sfVector3f pose3d, float angle);
sfVector2i		my_isometric_projection(sfVector3f pose3d);
int			match(char *str1, char *str2);
int			my_checkenv(char **env);

#endif	/* !MY_INFOG_ */
