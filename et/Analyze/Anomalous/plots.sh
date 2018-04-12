
plots="h1D_jpt1 h1D_jpt2 h1D_eta1 h1D_eta2 h1D_mjj h1D_met"

plots="hmelaDCP_VBF hmelaDCPggH_VBF hmelaD0minus_VBF hmelaD0minusggH_VBF hmelaDPhijj_VBF hmelaDPhiUnsignedjj_VBF"
plots="hmelaDCP_VBF hmelaDCPggH_VBF hmelaD0minus_VBF hmelaD0minusggH_VBF hmelaDPhijj_VBF hmelaDPhiUnsignedjj_VBF h1D_jpt1 h1D_jpt2 h1D_eta1 h1D_eta2 h1D_mjj h1D_met"




unset titlee
unset plot
unset cat


for plot in $plots
do

	cp ControlPlots_py ControlPlots.py


	sed -i 's@VARHERE@'${plot}'@g' ControlPlots.py ;


	python ControlPlots.py

done
