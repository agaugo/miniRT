#include "../../includes/minirt.h"

void	is_rt(char *file)
{
	char	*extension;
	int		path_len;
	int		ext_len;

	extension = ".rt";
	path_len = ft_strlen(file);
	ext_len = ft_strlen(extension);
	if (path_len < ext_len || !ft_strnstr(file + path_len - ext_len,
			extension, path_len))
	{
		printf("Error\nThe file does have the '.rt' extension.\n");
		exit(1);
	}
}
