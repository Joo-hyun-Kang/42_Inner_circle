#include "libft.h"

void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int main(void)
{
	printf("ft_isalpha is testing...\n");
	printf("argumnet -1 and output expect 0 : %d\n", ft_isalpha(-1));
	printf("argumnet EOF and output expect 0 : %d\n", ft_isalpha(EOF));
	printf("argumnet 65 and output expect 1 : %d\n", ft_isalpha(65));
	printf("argumnet 64 and output expect 0 : %d\n", ft_isalpha(64));
	printf("argumnet 127 and output expect 0 : %d\n", ft_isalpha(127));

	
	printf("\n\n");
	printf("ft_strlen is testing...\n");
	printf("argument abcd and output expect 4 : %zu\n", ft_strlen("abcd"));



	printf("\n\n");
	printf("ft_memcpy is testing...\n");

	{
		char	arr1[1];
		char	arr2[1];
		char	arr3[1];
		char	arr4[1];

		char	*p1 = ft_memset(arr1, 256, 1);
		char	*p2 = memset(arr2, 256, 1);
		char	*p3 = ft_memset(arr3, -1, 1);
		char	*p4 = memset(arr4, -1, 1);

		printf("argument 256 and ft_memset : %hhd\n", *p1);
		printf("argument 256 and memset : %hhd\n", *p2);
		printf("argument -1 and ft_memest : %hhd\n", *p3);
		printf("argument -1 and memest : %hhd\n", *p4);
	}


	printf("\n\n");
	printf("ft_strlcpy is testing...\n");
	
	{
		char *chs = "abc";
		char arr5[4];
		char arr6[4];
	
		printf("ft_strlcpy return value is %zu\n", ft_strlcpy(arr5, chs, 0));
		printf("ft_strlcpy dst is %s\n", arr5);
		printf("strlcpy return value is %zu\n", strlcpy(arr6, chs, 0));
		printf("strlcpy dst is %s\n", arr6);
	}
	

	printf("\n\n");
	printf("ft_strlcat is testing...\n");

	{
		char dst1[5] = "ab";
		char dst2[5] = "ab";
		char *src = "c";

 		printf("ft_strlcat return value is %zu\n", ft_strlcat(dst1, src, 3));
 		printf("ft_strlcat dst is %s\n", dst1);
		printf("strlcat return value is %zu\n", strlcat(dst2, src, 3));
 		printf("strlcat dst is %s\n", dst2);
	}

	printf("\n\n");
	printf("ft_strdup is testing...\n");
	
	{
		char	*arr = "abcd";
		char	*temp1 = ft_strdup(arr);
		char	*temp2 = strdup(arr);
		printf("ft_strdup : %s\n", temp1);
		printf("strdup : %s\n", temp2);
	}

	printf("\n\n");
	printf("ft_memcmp is testing...\n");

	{
		printf("ft_memcmp : %d\n", ft_memcmp("abcdefghij", "abcdefgxyz", 7));
		printf("memcmp : %d\n", memcmp("abcdefghij", "abcdefgxyz", 7));
		printf("ft_memcmp : %d\n", ft_memcmp("zyxbcdefgh", "abcdefgxyz", 0));
		printf("memcmp : %d\n", memcmp("zyxbcdefgh", "abcdefgxyz", 0));
	}

	printf("\n\n");
	printf("ft_strlcat is testing...\n");
	
	{
		char	*dest;
		int		dest_len;

		dest_len = 15;
		dest = (char *)malloc(sizeof(*dest) * dest_len);
		memset(dest, 0, dest_len);
		memset(dest, 'r', 6);
		dest[10] = 'a';
		printf("ft_strlcat: %zu\n", ft_strlcat(dest, "lorem ipsum dolor sit amet", 0));
		printf("%s\n", dest);
		free(dest);
	}

	{
		char	*dest;
		int		dest_len;

		dest_len = 15;
		dest = (char *)malloc(sizeof(*dest) * dest_len);
		memset(dest, 0, dest_len);
		memset(dest, 'r', 6);
		dest[10] = 'a';
		printf("strlcat: %zu\n", strlcat(dest, "lorem ipsum dolor sit amet", 0));
		printf("%s\n", dest);
		free(dest);
	}

	{
		char	dest[30] = "123";
		char	*src = "456789";
		
		size_t ret = strlcat(dest, src, 3);
		printf("return : %zu, value : %s\n", ret, dest);
	}

	printf("\n\n");
	printf("ft_atoit is testing...\n");

	{
		printf("ft_atoi : %d\n", ft_atoi("99999999999999999999999999"));
		printf("atoi : %d\n", atoi("99999999999999999999999999"));
	}

	
	printf("\n\n");
	printf("ft_substr is tesing\n");

	{
			char *s = ft_substr("tripouille", 0, 42000);;
			printf("%s\n", s);
			free(s);
	}

	printf("\n\n");
	printf("ft_strtrim is testing\n");

	{
		char arr[] = "  \t \t \n   \n\n\n\t";
		char set[] = " \n\t";
		
		char *result = ft_strtrim(arr, set);
		printf("%s\n", result);
		free(result);
	}

	printf("\n\n");
	printf("ft_itoa is testing\n");
	
	{
		int num1 = 1234;
		int num2 = -1234;
		
		char *res1 = ft_itoa(num1);
		char *res2 = ft_itoa(num2);
		
		printf("ft_itoi res1 : %s\n", res1);
		printf("ft_itoi res2 : %s\n", res2);

		free(res1);
		free(res2);
		
		res1 = NULL;
		res2 = NULL;
	}
}
