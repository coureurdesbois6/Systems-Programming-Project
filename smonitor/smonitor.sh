start_monitoring()
{
	while true; do
    for i in "${servers[@]}"
	do
		if ping -W 500 -c 1 $i &> /dev/null
		then
  			#echo up
  			display_server_status $i
		else
  			#echo down
  			echo "$i is DOWN"
		fi
	done
	sleep 2
	#echo -ne " \r"
	#echo -en "\033[0"
	echo -ne "\r\033[${#servers[@]}A\033[0K$@"
	done
	
}

display_server_status()
{
	#out=`ping -W 1000 -c 2 192.168.1.43 | grep -oE '([0-9]{1,3}\.?){4,}' | head -1`
	out=`ping -c 1 $1 | grep -oE 'time=[0-9]*\.[0-9]*' | head -1`
	echo "$1 is up, ping: $out"
}

read_servers() {
	i=0;
	touch servers.txt
	for j in `cat servers.txt` 
	do
   		servers[$i]=$j; 
    	i=$(($i+1)); 
  	done 
  	echo "`grep . servers.txt`" > servers.txt
}


declare -a servers
read_servers


if [ $# -eq 0 ]
  then
    echo "usage: smonitor [-start] [-add server_ip] [-remove server_ip]"
    exit 1;
fi



if [[ $1 == -start ]]
then
	clear
	start_monitoring
elif [[ $1 == -add ]]
then
	if [[ -z $2 ]]
	then
		echo "usage: smonitor [-add server_ip]"
		exit 1;
	else
		#arr=( "${servers[@]}" $2 )
		#echo $'\n' >> servers.txt
		echo $2 >> servers.txt
		echo "added"
	fi
elif [[ $1 == -show ]]
then
	for i in "${servers[@]}"
	do
  	echo "$i"
	done
elif [[ $1 == -remove ]]
then
	if [[ -z $2 ]]
	then
		echo "usage: smonitor [-remove server_ip]"
		exit 1;
	else
		sed -i -e "s/$2//g" servers.txt
	fi
fi


