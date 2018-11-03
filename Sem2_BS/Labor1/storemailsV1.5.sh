#!/bin/bash
#v1.5
#./StoreMails.sh -d QWERTZ/ ../Beispielmails/*.eml


_timeStamp=1
_email_files=""
_pathToStore='Mailarchive/'
_n_Count=0

_date_start=`date '+%Y-%m-%d %H:%M:%S'`
_date_end=''

_count_copied_emails=0
_count_touched_emails=0
_log=1  # 0 -> OFF || 1 -> Just echo || 2 -> Write to Logfie
_logfile="__LOG - $_date_start.txt"

function Logfile() {

    for Messages in "$@"; do

        if [ $_log -gt 0 ]; then        
            echo "$Messages"
        fi
        if [ $_log -gt 1  ]; then
            #log_all=cat "$logfile"
            echo "$(date '+%Y-%m-%d %H:%M:%S') ---    $Messages" >> "$_logfile"
        fi  
    done

}

#------------------------------------------------------------------------------------------------------------------------------

function PrintMessage() {
#    $1, $2, $3, ... is Message
  clear
  echo "    \ "
  echo "     \ "
  echo '                                    .::!!!!!!!!:.'
  echo '  .!!!!!:.                         .:!!!!!!!!!!!!'
  echo '  ~~~~!!!!!!.                  .:!!!!!!!!!UWWW$$$'
  echo '      :$$NWX!!:            .:!!!!!!XUWW$$$$$$$$$P'
  echo '      $$$$$##WX!:       .<!!!!UW$$$$"  $$$$$$$$#'
  echo '      $$$$$  $$$UX    :!!UW$$$$$$$$$   4$$$$$*'
  echo '      ^$$$B  $$$$\      $$$$$$$$$$$$   d$$R"'
  echo '      "*$bd$$$$         `*$$$$$$$$$$$o+#"'
  echo '           """"             """""""' 

  echo '------------------------------------------------------'
  echo ''  
  echo ''
  echo ''
  echo ''

  for Messages in "$@"; do
    echo "         $Messages"
  done
    
  echo ''
  echo ''
  echo ''
  echo ''
  echo '              Press any key to continue... '
  echo '------------------------------------------------------'


  read -n1 -r -p "" key
  echo ''
}

#------------------------------------------------------------------------------------------------------------------------------

function Mnt_to_Num() {
  _Mnt_to_Num='00'
  case "$1" in
  "Jan")    _Mnt_to_Num='01'
    ;;
  "Feb")    _Mnt_to_Num='02'
    ;;
  "Mar")    _Mnt_to_Num='03'
    ;;
  "Apr")    _Mnt_to_Num='04'
    ;;
  "Mai")    _Mnt_to_Num='05'
    ;;
  "Jun")    _Mnt_to_Num='06'
    ;;
  "Jul")    _Mnt_to_Num='07'
    ;;
  "Aug")    _Mnt_to_Num='08'
    ;;
  "Sep")    _Mnt_to_Num='09'
    ;;
  "Oct")    _Mnt_to_Num='10'
    ;;
  "Nov")    _Mnt_to_Num='11'
    ;;
  "Dec")    _Mnt_to_Num='12'
    ;;
  *)
    echo "Month not found!!!"
    _Mnt_to_Num='-1'
    ;;
  esac
  #return $_Mnt_to_Num
}

#------------------------------------------------------------------------------------------------------------------------------

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

#------------------------------------------------------------------------------------------------------------------------------

function CreateRep() {
  for Reps in "$@"; do    
    mkdir "$Reps"
  done
}

#------------------------------------------------------------------------------------------------------------------------------

function CopyFile() {
    # $1 is file to copy
    # $2 is path
    # cp -u -> kopiert nur, wenn Zieldatei älter als Quelldatei 
  cp -u "$1" "$2"

}

#------------------------------------------------------------------------------------------------------------------------------

function GetDate() {
# $1 is email     
    _yea=''
    _mnt=''
    _day=''
    _hrs=''
    _min=''
    _sec=''
    DSTRING= ``
    # Gibt den Datum aus
    DSTRING=$(grep -rI Date: "$1" | cut -d ":" -f 2)         
    # Mon, 19 Mar 2018 15
    _yea=$(echo $DSTRING | cut -d " " -f 4)
    _mnt=$(echo $DSTRING | cut -d " " -f 3)
    _day=$(echo $DSTRING | cut -d " " -f 2)
    _hrs=$(echo $DSTRING | cut -d " " -f 5)
    _min=`grep -rI Date: "$1" | cut -d ":" -f 3`
    _sec=`grep -rI Date: "$1" | cut -d ":" -f 4 | cut -d " " -f 1`      
    Mnt_to_Num "$_mnt"
    #PrintMessage "      Year: $_yea" "      Mnth: $_mnt" "      Day : $_day" "      Hour: $_hrs" "      Min : $_min" "      Sec : $_sec" "" "" "Month in num.: $_Mnt_to_Num"

} 

#------------------------------------------------------------------------------------------------------------------------------

function TimeModification() {

    GetDate "$_current_path/$1"
    #PrintMessage "$current_path/$1"
       
    # Jahr korrektur von 2018 -> 18
    _yea_2=$(echo "$_yea" | cut -c 3-)
    #Mon, 19 Mar 2018 15
    if [ $_day -lt 10 ]; then
        _date="$_yea_2$_Mnt_to_Num"0"$_day$_hrs$_min"
    else
        _date="$_yea_2$_Mnt_to_Num$_day$_hrs$_min"
    fi

    if [ $_day -gt -1 ]; then
            touch -m -t "$_date" "$_current_path/$1"
            touch -a -t "$_date" "$_current_path/$1"
            #stat "$_current_path/$1"
# OPTIONAL
            _count_touched_emails=`expr $_count_touched_emails + 1`
            Logfile "   ***$_count_touched_emails***" "$(stat "$_current_path/$1")" "------------------------------------------------------------------------------------------------------------------------------"
            #stat "$_current_path/$1"
#END
    fi

}

#------------------------------------------------------------------------------------------------------------------------------

function String_append(){
    _n_count=1
    String_append=""

    for part in "$@"; do
        if [ $_n_count -gt 1 ]; then
            String_append=$( echo "$String_append $part")
                
            test_string=".eml"  
            if [[ "$part" == *"${test_string}"* ]]; then
                _n_count=0
                TimeModification "$String_append"
                #PrintMessage "$part" "" "$String_append"
                String_append=""
            fi
        else
            String_append=$( echo "$part") 
            test_string=".eml"  
            if [[ "$part" == *"${test_string}"* ]]; then
                _n_count=0
                TimeModification "$String_append"
                #PrintMessage "$part" "" "$String_append"
                String_append=""
            fi       
        fi
        _n_count=`expr $_n_count + 1`
    done
    #PrintMessage "$String_append"

}

#------------------------------------------------------------------------------------------------------------------------------

function ListEmails() {
    _year_dir=$(ls "$_pathToStore")

    for _year in $_year_dir; do
        _month_dir=$(ls "$_pathToStore$_year")   
        #PrintMessage "$month_dir"

        for _month in $_month_dir; do        
            _day_dir=$(ls "$_pathToStore$_year/$_month") 

            for _day in $_day_dir; do 
                _emails=$(ls "$_pathToStore$_year/$_month/$_day")

                if [ $_day_2 -lt 10 ]; then
                     _current_path="$_pathToStore$_year/$_month/0$_day"
                else
                     _current_path="$_pathToStore$_year/$_month/$_day"
                fi    
                String_append $(echo ${_emails[@]})
            done    
        done
    done

}

#------------------------------------------------------------------------------------------------------------------------------

function ProcessEmail() {
    let counter=0

    for _email in "$@"; do
    #for _email in $*; do 
     #PrintMessage "$_email"
      if [ $counter -gt $_n_Count ]; then

          GetDate "$_email"
          # create rep if not exist
          CheckRep "$_pathToStore$_yea"
          if [ $_CheckRep -eq -1 ]; then
            CreateRep "$_pathToStore$_yea"
          fi 

          # create rep if not exist
          CheckRep "$_pathToStore$_yea/$_Mnt_to_Num"
          if [ $_CheckRep -eq -1 ]; then
            CreateRep "$_pathToStore$_yea/$_Mnt_to_Num"
          fi 

          # create rep if not exist
          if [ $_day -lt 10 ]; then
            CheckRep "$_pathToStore$_yea/$_Mnt_to_Num/0$_day"
            if [ $_CheckRep -eq -1 ]; then
              CreateRep "$_pathToStore$_yea/$_Mnt_to_Num/0$_day"
            fi 
          else
            CheckRep "$_pathToStore$_yea/$_Mnt_to_Num/$_day"
            if [ $_CheckRep -eq -1 ]; then
              CreateRep "$_pathToStore$_yea/$_Mnt_to_Num/$_day"
            fi 
          fi
          
          if [ $_day -lt 10 ]; then
            CopyFile "$_email" "$_pathToStore$_yea/$_Mnt_to_Num/0$_day"
          else
            CopyFile "$_email" "$_pathToStore$_yea/$_Mnt_to_Num/$_day"
          fi

# OPTIONAL
          _count_copied_emails=`expr $_count_copied_emails + 1`
          Logfile "   ***$_count_copied_emails***" "-> COPY -> $_email" 
          if [ $_day -lt 10 ]; then
              Logfile "->  TO  -> $_pathToStore$_yea/$_Mnt_to_Num/0$_day" 
          else
              Logfile "->  TO  -> $_pathToStore$_yea/$_Mnt_to_Num/$_day"
          fi
          Logfile "--------------------------------------------------------------------------------"
#END

      else
        counter=`expr $counter + 1`
        #let counter=counter+1
     fi
    done
}

#------------------------------------------------------------------------------------------------------------------------------

if [ "$#" -eq 0 ] || [ "$1" == '-h' ]
then
  PrintMessage "Usage:" "./Storemails.sh [Option] [Archive_Pfad/ Maildateien/] [ Maildateien/]" "" "Options:" "    -h  Help" "    -t  Timestamp" "    -d  Other Archive Directory"
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
  # gebe alle Parameter aus 
  PrintMessage "$@"
  exit 1
fi

if [ $_timeStamp -eq 1 ]; then
    #TimeModification
    ListEmails
fi

_date_end=`date '+%Y-%m-%d %H:%M:%S'`
PrintMessage "     Copied emails :     $_count_copied_emails" "     Touched emails:     $_count_touched_emails" "" "     Start:" "       $_date_start" "     End:" "       $_date_end"
