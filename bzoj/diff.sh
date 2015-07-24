export CXX="clang++"
export CXXFLAGS="-Wall -Wextra -g3 -DYGHDEBUG"
name=2761
bname=2761_b
gen_name=2761_gen.py
make $name 
make $bname
for i in {1..100}:
do
	python $gen_name>$name.in
	./$name < $name.in>$name.out
	./$bname<$name.in>$name.ans
	if(diff -q -Bb  $name.out $name.ans)
	then
	echo $i AC
	else 
		echo ! $i
		exit
	fi
done
