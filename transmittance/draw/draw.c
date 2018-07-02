void draw(){

  int i = 0;
  for(i = 10 ; i < 50 ; i++){
    if(i == 11 || i == 15 || i == 23 || i == 31 || i == 33 || i == 34 || i == 37 || i == 38 || i == 43 || i == 44){

      string i_str = to_string(i);
      string front = "J";
      string back = "_100ns";

      string filename = front + i_str + back;

      string filler = "../";
      string filler2 = ".his.txt";
      string file = filler + filename + filler2;


      ifstream myfile;
      int channel , count;
      string ss;

      TCanvas *c1 = new TCanvas("c1","c1",800,600);

      TH1F *h = (TH1F *)gROOT->FindObject("h1"); // gROOT or gDirectory
      delete h;//prevent potential memory leak
      TH1F *h1 = new TH1F("h1","",4200,0,4200);

      myfile.open(file);
      while(myfile>>channel>>ss>>count){
	h1->SetBinContent(channel, count);
      }
      myfile.close();

      string title_front = front;
      string title_back = ", Gate : 100ns, Threshold : 7mv";
      string title = title_front + i_str + title_back;
      h1->SetTitle(title.c_str());
      h1->SetXTitle("channel");
      h1->SetYTitle("count");
      h1->Draw();

      //fitting
      gStyle->SetOptFit(1111);
      //(pcev : 1111)(p : print probablility, c : print Chi-square/number of degrees of freedom,  e : print errors (if e=1, v must be 1), v = 1 print name/values of parameters)
      gStyle->SetOptStat("n");
      //print only the histogram's name(h1)//gStyle->SetOptStat("nemr") is the default. (e : number of entries printed, m : mean value printed, r : rms printed)

      //get the signal peak position in the given range between bins 150, 500
      h1->GetXaxis()->SetRange(150,500);
      int peak_pos =  h1->GetMaximumBin();//signal peak position
      //h1->GetMaximum(); //returns maximum value(count) between bins 150,500
      //  h1->GetXaxis()->SetRange();//return to default range
      h1->GetXaxis()->SetRange(0,1200);

      h1->Fit("gaus","","",peak_pos - 60,peak_pos + 100);
      TF1 *fit = h1->GetFunction("gaus");
      double mean = fit->GetParameter(1);//p0*exp(-0.5*((x-p1)/p2)^2)// p0 = 0, p1 = 1, p2 = 2
      double chi2 = fit->GetChisquare();
      double ndf = fit->GetNDF();
      //  cout<<chi2/ndf<<endl;

      ofstream outfile("test.txt", ios::app);//ios::app is to append the existing file, not overwrite.
      outfile<<filename<<"\n"
	     <<"mean     : "<<mean<<"\n"
	     <<"chi2     : "<<chi2<<"\n"
	     <<"ndf      : "<<ndf<<"\n"
	     <<"chi2/ndf : "<<chi2/ndf<<"\n"<<endl;
      outfile.close();
  
      string dir = "output/";
      string png = ".png";
      string comb = dir + filename + png;
      const char *output = comb.c_str();
      c1->Print(output);

      c1->Close();
      
    }
  }

  return 0;
}
