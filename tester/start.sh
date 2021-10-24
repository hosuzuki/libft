#!/bin/bash

#PATH_TEST=$(dirname $(readlink -f $0))
PATH_TEST="$(cd "$(dirname "$0")" && pwd -P)"
#変数の中をのぞき見るには、${変数名}

#$0:スクリプトの名前そのものを表す。
#$1,$2,$3...:引数を表す。# cat test.sh
#!/usr/bin/bash
#echo "$0" "$1" "$2"
# ~# ./test.sh aa
#./test.sh aa

##-Pはわからない。。
PATH_LIBFT="$(cd "$(dirname "$0")/.." && pwd -P)"

#exec 2> /dev/null
#exec コマンドを使うと、同じプロセス内で外部コマンドが実行される。
#exec > output のように実行すると、それ以降実行されるコマンドの標準出力については、
#output ファイルにリダイレクトされる。元に戻すためには、exec > /dev/tty を実行する。

#2: 標準エラー出力
#>はリダイレクト、ここだと、標準エラー出力を空ファイルに捨てている。
#/dev/nullというのはunixのスペシャルファイルの事で、空ファイルの事です。

#あるコマンドを実行させたいときに、シェルスクリプトを実行してコマンドを実行させる場合
#プロセス上ではコマンドを実行させるために起動したシェルスクリプトのプロセスが
#そのコマンドが終了するまで残ります。
#例えば、sleepコマンドを起動させるシェルスクリプト実行させて、
#その後、すぐに実行を中断させ(Ctrl+z)、psコマンドで実行中のプロセスを確認すると、

#source ${PATH_TEST}/core.sh
#「source」コマンドは、ファイルに書かれたコマンドを現在のシェルで実行する、
#というコマンドです。主にシェルの設定ファイルを反映させる際に使用します。
source ${PATH_TEST}/part_1.sh
source ${PATH_TEST}/part_2.sh
source ${PATH_TEST}/bonus.sh
source ${PATH_TEST}/additional.sh
COMPIL_FLAGS="gcc -Wextra -Wall -Werror"

if [ -e ${PATH_TEST}/mains/m_$1.c ]
then
	MAIN_FILE="${PATH_TEST}/mains/m_$1.c"
	COMPIL_ARGS="${COMPIL_FLAGS} ${MAIN_FILE} -L${PATH_LIBFT} -lft -I${PATH_LIBFT}"
	printf "$1.c: "
	${COMPIL_ARGS}
	./a.out
	printf "\n" 
#if [$1 -eq tab_all_part]
#then
#	echo "it works!\n"
#fi
else
#for 変数名 in 文字列の集合
#do
# 処理
#done 
	for arg in ${Part1_func[*]} ${Part2_func[*]} ${Bonus_func[*]} ${Additional_func[*]}
#$@	全部の引数を個別として処理
	do
		MAIN_FILE="${PATH_TEST}/mains/m_$arg.c"
		COMPIL_ARGS="${COMPIL_FLAGS} ${MAIN_FILE} -L${PATH_LIBFT} -lft -I${PATH_LIBFT}"
		printf "${arg}.c: "
		${COMPIL_ARGS}
	./a.out
		printf "\n" 
	done
fi

#	case "${arg}" in
#		*ft_*)	for part in ${tab_all_part[*]}
#	esac
#done
#case 文字列 in
#	パターン1) 文字列がパターン1に該当したときのコマンド ;;
#	パターン2) 文字列がパターン2に該当したときのコマンド ;;
#	*) 文字列がどのパターンにも該当しなかったときのコマンド ;;
#esac

