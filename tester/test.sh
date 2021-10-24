#!bin/bash

PATH_TEST="$(cd "$(dirname "$0")" && pwd -P)"
#PATH_LIBFT="$(cd "$(dirname "$0")"/.. && pwd -P)" //this one is OK too.
PATH_LIBFT="$(cd "$(dirname "$0")/.." && pwd -P)"


#dirs=`find $dir_path -type f -name libft*`
#find $dir_path -type f -name *.jpg

#for dir in $dirs;
#do
#	echo $dir
#done

if [ -e ${PATH_LIBFT}/libft.h ]
	then
cp ${PATH_LIBFT}/libft.h ${PATH_TEST}
fi
if [ -e ${PATH_LIBFT}/libft.a ]
	then
cp ${PATH_LIBFT}/libft.a ${PATH_TEST}
fi

