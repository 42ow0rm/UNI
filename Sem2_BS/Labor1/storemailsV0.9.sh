#!/bin/bash
#v0.9
_timeStamp=1
_pathToEmails=''
_email_files=""
_pathToStore='Mailarchive/'
_n_Count=0

function Mnt_to_Num() {
  _Mnt_to_Num=0
  _Mnt_long='00'
  case "$1" in
  "Jan")
    _Mnt_to_Num=1
    _Mnt_long='01'
    ;;
  "Feb")
    _Mnt_to_Num=2
    _Mnt_long='02'
    ;;
  "Mar")
    _Mnt_to_Num=3
    _Mnt_long='03'
    ;;
  "Apr")
    _Mnt_to_Num=4
    _Mnt_long='04'
    ;;
  "Mai")
    _Mnt_to_Num=5
    _Mnt_long='05'
    ;;
  "Jun")
    _Mnt_to_Num=6
    _Mnt_long='06'
    ;;
  "Jul")
    _Mnt_to_Num=7
    _Mnt_long='07'
    ;;
  "Aug")
    _Mnt_to_Num=8
    _Mnt_long='08'
    ;;
  "Sep")
    _Mnt_to_Num=9
    _Mnt_long='09'
    ;;
  "Oct")
    _Mnt_to_Num=10
    _Mnt_long='10'
    ;;
  "Nov")
    _Mnt_to_Num=11
    _Mnt_long='11'
    ;;
  "Dec")
    _Mnt_to_Num=12
    _Mnt_long='12'
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
  #PrintMessage "$@"
  if [ ! -d "$1" ]; then
    _CheckRep=(-1);
  fi 
  if [ -d "$1" ]; then
    _CheckRep=(1);
  fi  

  #return $_CheckRep
}

function CreateRep() {
  for Reps in "$@"; do    
    mkdir "$Reps"
  done
}

function CopyFile() {
    # $1 is file to copy
    # $2 is path
    # cp -u -> kopiert nur, wenn Zieldatei älter als Quelldatei 
  cp -u "$1" "$2"

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

function ProcessEmail() {

    let counter=0

    for _email in "$@"; do
    #for _email in $*; do 
     #PrintMessage "$_email"
      if [ $counter -gt $_n_Count ]; then
          _yea=''
          _mnt=''
          _day=''
          _hrs=''
          _min=''
          _sec=''
          DSTRING= ``

          # Gibt den Datum aus
          #DSTRING=`grep -rI Date: "$_email"/ | cut -d ":" -f 3`
          DSTRING=$(grep -rI Date: "$_email" | cut -d ":" -f 2)
         
         # Mon, 19 Mar 2018 15
          _yea=$(echo $DSTRING | cut -d " " -f 4)
          _mnt=$(echo $DSTRING | cut -d " " -f 3)
          _day=$(echo $DSTRING | cut -d " " -f 2)
          _hrs=$(echo $DSTRING | cut -d " " -f 5)
          _min=`grep -rI Date: "$_email" | cut -d ":" -f 3`
          _sec=`grep -rI Date: "$_email" | cut -d ":" -f 4 | cut -d " " -f 1`
          
          Mnt_to_Num "$_mnt"

          #PrintMessage "      Year: $_yea" "      Mnth: $_mnt" "      Day : $_day" "      Hour: $_hrs" "      Min : $_min" "      Sec : $_sec" "" "" "Month in num.: $_Mnt_to_Num"

          # create rep if not exist
          CheckRep "$_pathToStore$_yea"
          if [ $_CheckRep -eq -1 ]; then
            CreateRep "$_pathToStore$_yea"
          fi 

          # create rep if not exist
          CheckRep "$_pathToStore$_yea/$_Mnt_long"
          if [ $_CheckRep -eq -1 ]; then
            CreateRep "$_pathToStore$_yea/$_Mnt_long"
          fi 

          # create rep if not exist
          if [ $_day -lt 10 ]; then
            CheckRep "$_pathToStore$_yea/$_Mnt_long/0$_day"
            if [ $_CheckRep -eq -1 ]; then
              CreateRep "$_pathToStore$_yea/$_Mnt_long/0$_day"
            fi 
          else
            CheckRep "$_pathToStore$_yea/$_Mnt_long/$_day"
            if [ $_CheckRep -eq -1 ]; then
              CreateRep "$_pathToStore$_yea/$_Mnt_long/$_day"
            fi 
          fi
          
          if [ $_day -lt 10 ]; then
            CopyFile "$_email" "$_pathToStore$_yea/$_Mnt_long/0$_day"
          else
            CopyFile "$_email" "$_pathToStore$_yea/$_Mnt_long/$_day"
          fi

          if [ $_timeStamp -eq 1 ]; then
            # Jahr korrektur von 2018 -> 18
            _yea_2=$(echo "$_yea" | cut -c 3-)

            # Pfad korrektur entferne Beispielmails/ vom Pfad
            _email_name=$(echo "$_email" | cut -c 15-)

            if [ $_day -lt 10 ]; then
              touch -m -t "$_yea_2$_Mnt_long"0"$_day$_hrs$_min" "$_pathToStore$_yea/$_Mnt_long/0$_day/$_email_name"
              stat "$_pathToStore$_yea/$_Mnt_long/0$_day/$_email_name"
            else
              touch -m -t "$_yea_2$_Mnt_long$_day$_hrs$_min" "$_pathToStore$_yea/$_Mnt_long/$_day/$_email_name"
              stat "$_pathToStore$_yea/$_Mnt_long/$_day/$_email_name"
            fi
          fi
      else
        counter=`expr $counter + 1`
        #let counter=counter+1
     fi
    done
}

if [ "$#" -eq 0 ] || [ "$1" == '-h' ]
then
  PrintMessage "Usage: ./Storemails.sh [Option] [Pfad/Maildateien/] [Maildateien/]" "" "Options:" "    -h  Help" "    -t  Timestamp" "    -d  Other Directory"
  exit 1

elif [ "$1" == '-t' ]
then 
  _timeStamp=1
  _n_Count=1
  ProcessEmail "$@"

elif [ "$1" == '-d' ]
then 
  _pathToStore="$2"
  _n_Count=2

  # create rep if not exist
  CheckRep $_pathToStore
  if [ $_CheckRep -eq -1 ]; then
    CreateRep "$_pathToStore"
  fi
  ProcessEmail "$@"

else
  # gebe alle Parameter in jeweils eine neue Zeile ab 
  for a in "$@"; do
    echo "$a"
  done
  exit 1
fi

#------------------------------------------------------------------------------------------------------------------------------
