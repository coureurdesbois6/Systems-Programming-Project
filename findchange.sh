#This script is all about changing words or sentences. You don't have to remember which txt file you should change. This script gives you the name and also the chance to change that words or sentences. 

#DIR shows where we are and also example for other process
DIR="$( cd "$( dirname "$0" )" && pwd )"
echo "Example dir: $DIR"
echo ""


#Checks if there are enough arguments.
if [ $# -ne 3 ]; then
 echo "usage: findchange [-C/-R] [word] [path]"
 else


# -C CHECKS ONE DIRECTORY.
  if [ $1 = "-C" ]; then
 dir1=$3
 cd $dir1
 DIR=`pwd`
 grep --color=always -wHn "$2" *\.* #GETS DIR FROM USER AND TRYING TO FIND THE WORD
 declare -i x=`cd $dir1 | grep --color=always -wHn "$2" *\.* | wc -l`
  if [ $x -eq 0 ]; then
   echo "'$2' couldn't found in your current directory. "
   else
     echo "Do you want to make changes to the word you choose?[y/n]"
 read -r b
 if [ $b = "y" ]; then
  echo "New coming word:"
  read -r a

  echo "Select one of the specified directories( it is coming before this ':' )="
  read -r path
  echo "Line number of word to change:"
  read -r linenum
  sed -i.bak -e "$linenum s/$2/$a/g" $path
 fi
  fi


elif [ $1 = "-R" ]; then
dir2=$3
cd $dir2
DIR=`pwd`
 grep --color=always -rwHn "$2" ${DIR} #GETS DIR FROM USER AND TRYING TO FIND THE WORD
 declare -i x=`cd $dir2 | grep --color=always -rwHn "$2" $dir2 | wc -l`
  if [ $x -eq 0 ]; then
   echo "'$2' couldn't found in your tree of your current directory."
   else
    echo "Do you want to make changes to the word you choose?[y/n]"
 read -r b
 if [ $b = "y" ]; then
  echo "New word:"
  read -r a
  echo "Select one of the specified directories( it is coming before this ':' ):"
  read -r path
  echo "Line number of word to change:"
  read -r linenum
  sed -i.bak -e "$linenum s/$2/$a/g" $path
 fi
  fi


else
 echo 'usage: findchange [-C/-R] [word] [path]'
fi
fi