{
  int i = 11;
  TCanvas *c1 = new TCanvas("c1",/* (name_front + i_str).c_str() */"c1", 200, 10, 2100, 1500);
  c1->Divide(3,3);
  TCanvas *c2 = new TCanvas("c2",/* (name_front + i_str).c_str() */"c2", 200, 10, 2100, 1500);
  c2->Divide(3,3);  
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

      string dir_03052018 = "../../03052018/";
      string dir_22052018 = "../../22052018/";
      
      string dir_original = "J_longitudinal_mark_top_left_20171219/";
      string dir_before_irr = "PbWO4_beofre_irr_top_left_02052018/";
      string dir_27min_60cm = "PbWO4_27min_60cm_irr_top_left_03052018/";
      string dir_27X2min_60cm = "PbWO4_27X2min_60cm_irr_top_left_03052018/";
      string dir_30min_15cm_03052018 = "PbWO4_30min_15cm_irr_top_left_03052018/";
      string dir_partially_naturally_cured_22052018 = "PbWO4_Partial_Natural_Cure_top_left_22052018/";
      string dir_30min_15cm_22052018 = "PbWO4_30min_15cm_irr_top_left_22052018/";
      string dir_30X2min_15cm_22052018 = "PbWO4_30X2min_15cm_irr_top_left_22052018/";

      string dir_giessen = "Giessen/";
      
      //integer to string
      string name_front = "J";
      string i_str;
      stringstream ss;
      ss << i;
      i_str = ss.str();
      string name_back = ".Sample.Raw.csv";

      string name_giessen_before_back = "_before.csv";
      string name_giessen_irr_back = "_irr.csv";      
      
      string file_before_input = dir_03052018 + dir_before_irr + name_front + i_str + name_back;
      string file_27min_60cm_input = dir_03052018 + dir_27min_60cm + name_front + i_str + name_back;
      string file_27X2min_60cm_input = dir_03052018 + dir_27X2min_60cm + name_front + i_str + name_back;
      string file_30min_15cm_input_03052018 = dir_03052018 + dir_30min_15cm_03052018 + name_front + i_str + name_back;    

      string file_partially_naturally_cured_22052018 = dir_22052018 + dir_partially_naturally_cured_22052018 + name_front + i_str + name_back;
      string file_30min_15cm_input_22052018 = dir_22052018 + dir_30min_15cm_22052018 + name_front + i_str + name_back;    
      string file_30X2min_15cm_input_22052018 = dir_22052018 + dir_30X2min_15cm_22052018 + name_front + i_str + name_back;    
      
      string file_giessen_before = dir_03052018 + dir_giessen + name_front + i_str + name_giessen_before_back;
      string file_giessen_irr = dir_03052018 + dir_giessen + name_front + i_str + name_giessen_irr_back;      

      //  const char* file_before_input = file_before_input_str.c_str();
  
      string dummy;

      double wavelength_db;
      double transmittance_db;
      //     double transmittance_original_db, transmittance_before_irr_db, transmittance_27min_60cm_db, transmittance_27X2min_60cm_db, transmittance_30min_15cm_db, transmittance_30X2min_15cm_db;
      vector<double> wavelength;
      vector<double> transmittance_original, transmittance_p_n_cured_22052018, transmittance_before_irr, transmittance_27min_60cm, transmittance_27X2min_60cm, transmittance_30min_15cm_03052018, transmittance_30min_15cm_22052018, transmittance_30X2min_15cm_22052018;

      vector<double> wavelength_giessen;
      vector<double> transmittance_giessen_before, transmittance_giessen_irr;


      
      /////delta K///////////////
      const double d = 0.2;//crystal length 20cm in meter unit
      vector<double> dk_27min_60cm, dk_27X2min_60cm, dk_30min_15cm_03052018, dk_30min_15cm_22052018, dk_30X2min_15cm_22052018;
      vector<double> dk_giessen;
      ///////////////////////////
      
      myfile.open(file_before_input.c_str());
      myfile>>dummy>>dummy;
      while(myfile>>wavelength_db>>dummy>>transmittance_db){
	wavelength.push_back(wavelength_db);
	transmittance_before_irr.push_back(transmittance_db);
      }
      myfile.close();

      myfile.open(file_27min_60cm_input.c_str());
      myfile>>dummy>>dummy;
      while(myfile>>wavelength_db>>dummy>>transmittance_db){
	transmittance_27min_60cm.push_back(transmittance_db);
      }
      myfile.close();

      myfile.open(file_27X2min_60cm_input.c_str());
      myfile>>dummy>>dummy;
      while(myfile>>wavelength_db>>dummy>>transmittance_db){
	transmittance_27X2min_60cm.push_back(transmittance_db);
      }
      myfile.close();

      myfile.open(file_30min_15cm_input_03052018.c_str());
      myfile>>dummy>>dummy;
      while(myfile>>wavelength_db>>dummy>>transmittance_db){
	transmittance_30min_15cm_03052018.push_back(transmittance_db);
      }
      myfile.close();

      
      myfile.open(file_partially_naturally_cured_22052018.c_str());
      myfile>>dummy>>dummy;
      while(myfile>>wavelength_db>>dummy>>transmittance_db){
	transmittance_p_n_cured_22052018.push_back(transmittance_db);
      }
      myfile.close();                

      myfile.open(file_30min_15cm_input_22052018.c_str());
      myfile>>dummy>>dummy;
      while(myfile>>wavelength_db>>dummy>>transmittance_db){
	transmittance_30min_15cm_22052018.push_back(transmittance_db);
      }
      myfile.close();

      myfile.open(file_30X2min_15cm_input_22052018.c_str());
      myfile>>dummy>>dummy;
      while(myfile>>wavelength_db>>dummy>>transmittance_db){
	transmittance_30X2min_15cm_22052018.push_back(transmittance_db);
      }
      myfile.close();                


      
      myfile.open(file_giessen_before.c_str());
      myfile>>dummy>>dummy>>dummy>>dummy;
      //      cout<<dummy<<endl;
      while(myfile>>wavelength_db>>transmittance_db>>dummy>>dummy>>dummy>>dummy>>dummy>>dummy>>dummy>>dummy>>dummy>>dummy>>dummy>>dummy>>dummy>>dummy>>dummy>>dummy){
	wavelength_giessen.push_back(wavelength_db);
	transmittance_giessen_before.push_back(transmittance_db);	
	//	cout<<transmittance_db<<endl;
      }
      myfile.close();    

      myfile.open(file_giessen_irr.c_str());
      myfile>>dummy>>dummy>>dummy>>dummy;
      while(myfile>>wavelength_db>>transmittance_db>>dummy>>dummy>>dummy>>dummy>>dummy>>dummy>>dummy>>dummy>>dummy>>dummy>>dummy>>dummy>>dummy>>dummy>>dummy>>dummy){
	transmittance_giessen_irr.push_back(transmittance_db);	
      }
      myfile.close();    
      

      /////delta K///////////////
      for(int j = 0 ; j < wavelength.size() ; j++){
	dk_27min_60cm.push_back((1/d)*log(transmittance_before_irr[j]/transmittance_27min_60cm[j]));
	dk_27X2min_60cm.push_back((1/d)*log(transmittance_before_irr[j]/transmittance_27X2min_60cm[j]));
	dk_30min_15cm_03052018.push_back((1/d)*log(transmittance_before_irr[j]/transmittance_30min_15cm_03052018[j]));
	dk_30min_15cm_22052018.push_back((1/d)*log(transmittance_before_irr[j]/transmittance_30min_15cm_22052018[j]));
	dk_30X2min_15cm_22052018.push_back((1/d)*log(transmittance_before_irr[j]/transmittance_30X2min_15cm_22052018[j]));				
	//	cout<<dk_27min_60cm[j]<<endl;
      }

      for(int j = 0 ; j < wavelength_giessen.size() ; j++){
	dk_giessen.push_back((1/d)*log(transmittance_giessen_before[j]/transmittance_giessen_irr[j]));		
	//	cout<<dk_27min_60cm[j]<<endl;
      }
      ///////////////////////////
      
      if(i == 11)    c1->cd(1);
      if(i == 23)    c1->cd(2);
      if(i == 31)    c1->cd(3);
      if(i == 33)    c1->cd(4);
      if(i == 34)    c1->cd(5);
      if(i == 37)    c1->cd(6);
      if(i == 38)    c1->cd(7);
      if(i == 43)    c1->cd(8);
      if(i == 44)    c1->cd(9);

      TMultiGraph *mg = new TMultiGraph();


      TGraph *gr_giessen_before = new TGraph(wavelength_giessen.size(), &wavelength_giessen[0], &transmittance_giessen_before[0]);
      gr_giessen_before->SetLineColor(38);
      gr_giessen_before->SetMarkerColor(38);
      gr_giessen_before->SetLineStyle(2);//1=solid, 2=dash, 3=dot, 4=dash-dot
      mg->Add(gr_giessen_before);

      TGraph *gr_giessen_irr = new TGraph(wavelength_giessen.size(), &wavelength_giessen[0], &transmittance_giessen_irr[0]);
      gr_giessen_irr->SetLineColor(46);
      gr_giessen_irr->SetMarkerColor(46);
      gr_giessen_irr->SetLineStyle(2);//1=solid, 2=dash, 3=dot, 4=dash-dot
      mg->Add(gr_giessen_irr);      
      
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

      TGraph *gr_30min_15cm = new TGraph(wavelength.size(), &wavelength[0], &transmittance_30min_15cm_03052018[0]);
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
      leg->AddEntry(gr_giessen_before, "Giessen before irr", "l");
      leg->AddEntry(gr_giessen_irr, "Giessen 30Gy irr", "l");      
      leg->AddEntry(gr_before, "before irr", "l");
      leg->AddEntry(gr_27min_60cm, "27min, 60cm", "l");
      leg->AddEntry(gr_27X2min_60cm, "54min, 60cm", "l");
      leg->AddEntry(gr_30min_15cm, "30min, 15cm", "l");
      leg->Draw();



      if(i == 11)    c2->cd(1);
      if(i == 23)    c2->cd(2);
      if(i == 31)    c2->cd(3);
      if(i == 33)    c2->cd(4);
      if(i == 34)    c2->cd(5);
      if(i == 37)    c2->cd(6);
      if(i == 38)    c2->cd(7);
      if(i == 43)    c2->cd(8);
      if(i == 44)    c2->cd(9);

      TMultiGraph *mg_dk = new TMultiGraph();

      TGraph *gr_dk_giessen = new TGraph(wavelength_giessen.size(), &wavelength_giessen[0], &dk_giessen[0]);
      gr_dk_giessen->SetLineColor(38);
      gr_dk_giessen->SetMarkerColor(38);
      gr_dk_giessen->SetLineStyle(2);//1=solid, 2=dash, 3=dot, 4=dash-dot
      mg_dk->Add(gr_dk_giessen);
      
      TGraph *gr_dk_27min_60cm = new TGraph(wavelength.size(), &wavelength[0], &dk_27min_60cm[0]);
      gr_dk_27min_60cm->SetLineColor(2);
      gr_dk_27min_60cm->SetMarkerColor(2);
      gr_dk_27min_60cm->SetMarkerStyle(1);
      mg_dk->Add(gr_dk_27min_60cm);

      TGraph *gr_dk_27X2min_60cm = new TGraph(wavelength.size(), &wavelength[0], &dk_27X2min_60cm[0]);
      gr_dk_27X2min_60cm->SetLineColor(6);
      gr_dk_27X2min_60cm->SetMarkerColor(6);
      gr_dk_27X2min_60cm->SetMarkerStyle(1);
      mg_dk->Add(gr_dk_27X2min_60cm);

      TGraph *gr_dk_30min_15cm_03052018 = new TGraph(wavelength.size(), &wavelength[0], &dk_30min_15cm_03052018[0]);
      gr_dk_30min_15cm_03052018->SetTitle((name_front + i_str).c_str());
      gr_dk_30min_15cm_03052018->SetLineColor(3);
      gr_dk_30min_15cm_03052018->SetMarkerColor(3);
      gr_dk_30min_15cm_03052018->SetMarkerStyle(1);
      gr_dk_30min_15cm_03052018->GetXaxis()->SetLimits(325, 900);
            gr_dk_30min_15cm_03052018->GetYaxis()->SetRangeUser(0,4.);
      //      gr_dk_30min_15cm_03052018->GetYaxis()->SetRangeUser(0,15.);
      //      gr_dk_30min_15cm_03052018->GetYaxis()->SetRangeUser(0,1.6);
      //      gr_dk_30min_15cm_03052018->GetYaxis()->SetRangeUser(0,.8);                  
      gr_dk_30min_15cm_03052018->GetXaxis()->SetTitle("Wavelength [nm]");
      gr_dk_30min_15cm_03052018->GetYaxis()->SetTitle("dK [1/m]");
      gr_dk_30min_15cm_03052018->Draw("APL");
      mg_dk->Draw("PL");
      
      TLegend *leg = new TLegend(0.6, 0.65, .9, .9);
      leg->AddEntry(gr_dk_giessen, "Giessen 30Gy", "l");      
      leg->AddEntry(gr_dk_27min_60cm, "27min, 60cm", "l");
      leg->AddEntry(gr_dk_27X2min_60cm, "54min, 60cm", "l");
      leg->AddEntry(gr_dk_30min_15cm_03052018, "30min, 15cm", "l");
      leg->Draw();      

      //draw lines to mark light emission range : [400, 800]nm
      /* TLine *line_start = new TLine(400,0,400,100);//(x1, y1, x2, y2) */
      /* TLine *line_finish = new TLine(800,31,800,100); */
      /* line_start->SetLineColor(4);//bleu */
      /* line_start->SetLineWidth(2); */
      /* line_start->SetLineStyle(4); */
      /* line_finish->SetLineColor(4);//bleu */
      /* line_finish->SetLineWidth(2); */
      /* line_finish->SetLineStyle(2);//dashed line */
      /* line_start->Draw("");//no need to say "SAME" */
      /* line_finish->Draw(""); */


      //radiation damage limit, dk = 1.1[1/m] for PANDA project
      TLine *line_limit = new TLine(325,1.1,900,1.1);//radiation damage limit, dK = 1.1[1/m] in PANDA project. 
      line_limit->SetLineColor(2);//red
      line_limit->SetLineWidth(2);
      line_limit->SetLineStyle(2);//dashed line
      line_limit->Draw();
      

    }
  }
  /* c1->Print("output/transmittance_with_giessen.eps"); */
  /* c2->Print("output/dk_wo_15irr_with_giessen.eps"); */
}
