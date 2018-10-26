#!/bin/bash
#v0.4
_timeStamp=1
_pathToEmails='Beispielmails1/'
_pathToStore='Mailarchive/'

function Mnt_to_Num() {
  _Mnt_to_Num=0
  case "$1" in
  "Jan")
    _Mnt_to_Num=1
    ;;
  "Feb")
    _Mnt_to_Num=2
    ;;
  "Mar")
    _Mnt_to_Num=3
    ;;
  "Apr")
    _Mnt_to_Num=4
    ;;
  "Mai")
    _Mnt_to_Num=5
    ;;
  "Jun")
    _Mnt_to_Num=6
    ;;
  "Jul")
    _Mnt_to_Num=7
    ;;
  "Aug")
    _Mnt_to_Num=8
    ;;
  "Sep")
    _Mnt_to_Num=9
    ;;
  "Oct")
    _Mnt_to_Num=10
    ;;
  "Nov")
    _Mnt_to_Num=11
    ;;
  "Dec")
    _Mnt_to_Num=12
    ;;
  *)
    echo "Month not found!!!"
    _Mnt_to_Num=-1
    ;;
  esac
  #return $_Mnt_to_Num
}

function CheckRep() {
  # Param $1 is the rep to check
  _CheckRep=0
  PrintMessage "$@"
  if [ ! -d "$1" ]; then
    _CheckRep=(-1);
  fi 
  if [ -d "$1" ]; then
    _CheckRep=(1);
  fi  

  #return $_CheckRep
}

function CreateRep() {
    mkdir "$1"
}

function PrintMessage() {
#    $1, $2, $3, ... is Message
  echo '----------------------------------------------------------'
  echo ''  
  echo ''
  echo ''
  echo ''

  for Messages in "$@"; do
    echo "$Messages"
  done
    
  echo ''
  echo ''
  echo ''
  echo ''
  echo 'Press any key to exit... '
  echo '----------------------------------------------------------'
  read -n1 -r -p "" key
  echo ''
}


if [ "$#" -eq 0 ] || [ "$1" == '-h' ]
then
  PrintMessage "Usage: ./Storemails.sh [Option] [Pfad/Maildateien/] [Maildateien/]" "" "Options:" "    -h  Help" "    -t  Timestamp" "    -d  Other Directory"
  exit 1

elif [ "$1" == '-t' ]
then 
  _timestamp=1
  _pathToEmails=$2

elif [ "$1" == '-d' ]
then 
  _pathToStore=$2
  _pathToEmails=$3

  # create rep if not exist
  CheckRep $_pathToEmails

elif [ "$1" == '-z' ]
then
  PrintMessage "Hello" 

else
  # gebe alle Parameter in jeweils eine neue Zeile ab 
  for a in "$@"; do
    echo "$a"
  done
  exit 1
fi

# create rep if not exist
CheckRep $_pathToEmails

if [ $test1 -eq -1 ]; then
  PrintMessage 'ERROR Path to emails is invalid!'
  exit -1
fi 


_yea=''
_mnt=''
_day=''
_hrs=''
_min=''
_sec=''
DSTRING= ``

# Gibt den Datum aus
#DSTRING=`grep -rI Date: eml/ | cut -d ":" -f 3`
DSTRING=`grep -rI Date: $_pathToEmails/ | cut -d ":" -f 3`

# Mon, 19 Mar 2018 15
_yea=$(echo $DSTRING | cut -d " " -f 4)
_mnt=$(echo $DSTRING | cut -d " " -f 3)
_day=$(echo $DSTRING | cut -d " " -f 2)
_hrs=$(echo $DSTRING | cut -d " " -f 5)
_min=`grep -rI Date: $_pathToEmails | cut -d ":" -f 4`
_sec=`grep -rI Date: $_pathToEmails | cut -d ":" -f 5 | cut -d " " -f 1`

PrintMessage "      Year: $_yea" "      Mnth: $_mnt" "      Day : $_day" "      Hour: $_hrs" "      Min : $_min" "      Sec : $_sec"


Mnt_to_Num "$_mnt"
echo "Month in num.: $_Mnt_to_Num"

read -n1 -r -p "Press any key to continue... " key
