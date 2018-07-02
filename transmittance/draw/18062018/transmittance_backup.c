{
  int i = 11;
  TCanvas *c1 = new TCanvas("c1",/* (name_front + i_str).c_str() */"c1", 200, 10, 2100, 1500);
  c1->Divide(3,3);
  for(i = 10 ; i < 50 ; i++){
    if(i == 11 || i == 23 || i == 31 || i == 33 || i == 34 || i == 37 || i == 38 || i == 43 || i == 44) {
      if(i == 11)    c1->cd(1);
      if(i == 23)    c1->cd(2);
      if(i == 31)    c1->cd(3);
      if(i == 33)    c1->cd(4);
      if(i == 34)    c1->cd(5);
      if(i == 37)    c1->cd(6);
      if(i == 38)    c1->cd(7);
      if(i == 43)    c1->cd(8);
      if(i == 44)    c1->cd(9);
      ifstream myfile;

      string dir = "../../03052018/";
      string dir_original = "J_longitudinal_mark_top_left_20171219/";
      string dir_before_irr = "PbWO4_beofre_irr_top_left_02052018/";
      string dir_27min_60cm = "PbWO4_27min_60cm_irr_top_left_03052018/";
      string dir_27X2min_60cm = "PbWO4_27X2min_60cm_irr_top_left_03052018/";
      string dir_30min_15cm = "PbWO4_30min_15cm_irr_top_left_03052018/"; 

      string name_front = "J";
      string i_str;
      stringstream ss;
      ss << i;
      i_str = ss.str();
      string name_back = ".Sample.Raw.csv";

      string file_beofre_input = dir + dir_before_irr + name_front + i_str + name_back;
      string file_27min_60cm_input = dir + dir_27min_60cm + name_front + i_str + name_back;
      string file_27X2min_60cm_input = dir + dir_27X2min_60cm + name_front + i_str + name_back;
      string file_30min_15cm_input = dir + dir_30min_15cm + name_front + i_str + name_back;    

      //  const char* file_beofre_input = file_beofre_input_str.c_str();
  
      string dummy;

      double wavelength_novec;
      double transmittance_novec;
      double transmittance_original_novec, transmittance_before_irr_novec, transmittance_27min_60cm_novec, transmittance_27X2min_60cm_novec, transmittance_30min_15cm_novec;
      vector<double> wavelength;
      vector<double> transmittance_original, transmittance_before_irr, transmittance_27min_60cm, transmittance_27X2min_60cm, transmittance_30min_15cm;
  
      myfile.open(file_beofre_input.c_str());
      myfile>>dummy>>dummy;
      while(myfile>>wavelength_novec>>dummy>>transmittance_novec){
	wavelength.push_back(wavelength_novec);
	transmittance_before_irr.push_back(transmittance_novec);
      }
      myfile.close();

      myfile.open(file_27min_60cm_input.c_str());
      myfile>>dummy>>dummy;
      while(myfile>>wavelength_novec>>dummy>>transmittance_novec){
	transmittance_27min_60cm.push_back(transmittance_novec);
      }
      myfile.close();

      myfile.open(file_27X2min_60cm_input.c_str());
      myfile>>dummy>>dummy;
      while(myfile>>wavelength_novec>>dummy>>transmittance_novec){
	transmittance_27X2min_60cm.push_back(transmittance_novec);
      }
      myfile.close();

      myfile.open(file_30min_15cm_input.c_str());
      myfile>>dummy>>dummy;
      while(myfile>>wavelength_novec>>dummy>>transmittance_novec){
	transmittance_30min_15cm.push_back(transmittance_novec);
      }
      myfile.close();    

      TMultiGraph *mg = new TMultiGraph();

      TGraph *gr_before = new TGraph(wavelength.size(), &wavelength[0], &transmittance_before_irr[0]);
      gr_before->SetLineColor(4);
      gr_before->SetMarkerColor(4);
      gr_before->SetMarkerStyle(1);
      mg->Add(gr_before);

      TGraph *gr_27min_60cm = new TGraph(wavelength.size(), &wavelength[0], &transmittance_27min_60cm[0]);
      gr_27min_60cm->SetLineColor(2);
      gr_27min_60cm->SetMarkerColor(2);
      gr_27min_60cm->SetMarkerStyle(1);
      mg->Add(gr_27min_60cm);

      TGraph *gr_27X2min_60cm = new TGraph(wavelength.size(), &wavelength[0], &transmittance_27X2min_60cm[0]);
      gr_27X2min_60cm->SetLineColor(6);
      gr_27X2min_60cm->SetMarkerColor(6);
      gr_27X2min_60cm->SetMarkerStyle(1);
      mg->Add(gr_27X2min_60cm);

      TGraph *gr_30min_15cm = new TGraph(wavelength.size(), &wavelength[0], &transmittance_30min_15cm[0]);
      gr_30min_15cm->SetTitle((name_front + i_str).c_str());
      gr_30min_15cm->SetLineColor(3);
      gr_30min_15cm->SetMarkerColor(3);
      gr_30min_15cm->SetMarkerStyle(1);
      gr_30min_15cm->GetXaxis()->SetLimits(325, 900);
      gr_30min_15cm->GetYaxis()->SetRangeUser(0,100);    
      gr_30min_15cm->GetXaxis()->SetTitle("Wavelength [nm]");
      gr_30min_15cm->GetYaxis()->SetTitle("Transmittance [%]");
      gr_30min_15cm->Draw("APL");
      mg->Draw("PL");

      TLegend *leg = new TLegend(0.6, 0.1, .9, .35);
      leg->AddEntry(gr_before, "before irr", "l");
      leg->AddEntry(gr_27min_60cm, "27min, 60cm", "l");
      leg->AddEntry(gr_27X2min_60cm, "54min, 60cm", "l");
      leg->AddEntry(gr_30min_15cm, "30min, 15cm", "l");
      leg->Draw();
    }
  }
  c1->Print("output/transmittance.eps");
}
