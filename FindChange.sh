#This script is all about changing words or sentences. You don't have to remember which txt file you should change. This script gives you the name and also the chance to change that words or sentences. 

#Written by Efe Ertekin

DIR="$( cd "$( dirname "$0" )" && pwd )"
echo "Example dir: $DIR"
echo ""
if [ $# -eq 0 ]; then
 echo "You need to give 2 arguments to console. First one should be '-C' or '-D'. '-C' is looking your current dir, '-D' is looking your current dir and your current dir's directories recursively. Second argument should be the word that you want to find."
 exit 0
fi
if [ $# -eq 1 ]; then
 echo "You should give 2 arguments. First one should be '-C' or '-D'. '-C' is looking your current dir, '-D' is looking your current dir and your current dir's directories recursively. Second argument should be the word that you want to find."
fi

if [ $1 = "-C" ]; then
 echo "Give a directory to perform your search:"
 read -r dir1
 cd $dir1 | grep --color=always -wHn "$2" *\.*
 declare -i x=`cd $dir1 | grep --color=always -wHn "$2" *\.* | wc -l`
  if [ $x -eq 0 ]; then
   echo "'$2' couldn't found in your current directory. "
   exit 0
  fi
 
 echo "Do you want to make changes to the word you choose?[y/n]"
 read -r b
 if [ $b = "y" ]; then
  echo "New coming word:"
  read -r a

  echo "Select one of the specified directories( it is coming before this ':' )="
  read -r path
  echo "Line number of word to change:"
  read -r linenum
  sed -i "$linenum s/$2/$a/g" $path
 fi

elif [ $1 = "-D" ]; then
 echo "Give a directory to perform your search:"
 read -r dir2
 cd $dir2 | grep --color=always -rwHn "$2" ${DIR}
 declare -i x=`cd $dir2 | grep --color=always -rwHn "$2" ${DIR} | wc -l`
  if [ $x -eq 0 ]; then
   echo "'$2' couldn't found in your tree of your current directory."
   exit 0
  fi

 echo "Do you want to make changes to the word you choose?[y/n]"
 read -r b
 if [ $b = "y" ]; then
  echo "New word:"
  read -r a
  echo "Select one of the specified directories( it is coming before this ':' ):"
  read -r path
  echo "Line number of word to change:"
  read -r linenum
  sed -i "$linenum s/$2/$a/g" $path

 fi

else
 echo 'First argument is wrong! You are allowed to use "-C" or "-D".'
fi
