channel=etau

mkdir files_nominal
mkdir files_up
mkdir files_down
mkdir files_JESup
mkdir files_JESdown
mkdir files_allTES

mkdir log
mkdir output
mkdir error

##can easily change to run on all systematics
syst=nominal

while read line 
do



file=`echo $line | awk -F " " '{print $2}' | awk -F "/" '{print $2}'`

if [[ $line == *"FinalSelection2D_relaxed"*  && $line != *"#"*  && ! -f files_$syst/$file ]] ; then

echo will submit  $file and $line now

	cp bss tmp
	echo $line >> tmp

	mv tmp job_${file}_${syst}.sh
	chmod u+w job_${file}_${syst}.sh
	cp submit_template.sub subm_${file}_${channel}.sub

	sed -i 's/EXECHERE/job_'${file}'_'${syst}'.sh/g' subm_${file}_${channel}.sub
	sed -i 's/FILEHERE/job_'${file}'_'${syst}'/g' subm_${file}_${channel}.sub

echo	condor_submit subm_${file}_${channel}.sub
fi

done <do_all2D_relaxed_${syst}
