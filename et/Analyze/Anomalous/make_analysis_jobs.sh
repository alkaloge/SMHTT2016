channel=etau

mkdir files_nominal
mkdir files_control
mkdir files_up
mkdir files_down
mkdir files_JESup
mkdir files_JESdown
mkdir files_allTES

mkdir log
mkdir output
mkdir error

##can easily change to run on all systematics

syst=$1
#syst=control
#syst=reweight

while read line 
do



file=`echo $line | awk -F " " '{print $2}' | awk -F "/" '{print $2}'`
filee=`echo $line | awk -F " " '{print $3}' | awk -F "/" '{print $2}'`

if [[ $line == *"FinalSelection2D_relaxed"*  && $line != *"#"*  && $line != *"python"*  && ! -f files_$syst/$filee ]] ; then

echo will submit  $file for $filee output $line now

	cp bss tmp
	echo $line >> tmp

	mv tmp job_${filee}_${syst}.sh
	chmod u+w job_${filee}_${syst}.sh
	cp submit_template.sub subm_${filee}_${channel}.sub

	sed -i 's/EXECHERE/job_'${filee}'_'${syst}'.sh/g' subm_${filee}_${channel}.sub
	sed -i 's/FILEHERE/job_'${filee}'_'${syst}'/g' subm_${filee}_${channel}.sub

	#echo . job_${filee}_${syst}.sh
	condor_submit subm_${filee}_${channel}.sub

fi

done <do_all2D_relaxed_${syst}







#done <do_reweighting.sh
