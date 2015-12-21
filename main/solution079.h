#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <set>
using namespace std;
//
//哎！这种方法超时了！！在面对下面这个测试用例，无能为力啊！！
//["aaaa","aaaa","aaaa","aaaa","aaab"]
//"aaaaaaaaaaaaaaaaaaaa"
//
//class Solution {
//	bool find(vector<string>& board, vector<vector<bool>> used, const string &word, int i, int j, int step) {
//		if (step == word.size()) {
//			return true;
//		}
//		used[i][j] = true;
//		int m = board.size();
//		int n = board[0].size();
//		if (i - 1 >= 0 && !used[i - 1][j] && word[step] == board[i - 1][j]) {
//			if (find(board, used, word, i - 1, j, step + 1))
//				return true;
//		}
//		if (i + 1 < m && !used[i + 1][j] && word[step] == board[i + 1][j]) {
//			if (find(board, used, word, i + 1, j, step + 1))
//				return true;
//		}
//		if (j + 1 < n && !used[i][j + 1] && word[step] == board[i][j + 1]) {
//			if (find(board, used, word, i, j + 1, step + 1))
//				return true;
//		}
//		if (j - 1 >= 0 && !used[i][j - 1] && word[step] == board[i][j - 1]) {
//			if (find(board, used, word, i, j - 1, step + 1))
//				return true;
//		}
//		return false;
//	}
//public:
//	bool exist(vector<string>& board, string word) {
//		vector<vector<bool>> used;
//		int m = board.size();
//		int n = board[0].size();
//		if (word.length() > m * n)
//			return false;
//		for (int i = 0; i < m; ++i) {
//			vector<bool> row(n, false);
//			used.push_back(row);
//		}
//		for (int j = 0; j < m; ++j) {
//			for (int k = 0; k < n; ++k) {
//				if (board[j][k] == word[0]) {
//					used[j][k] = true;
//					if (find(board, used, word, j, k, 1))
//						return true;
//
//					for (int i = 0; i < m; ++i) {
//						fill(used[i].begin(), used[i].end(), false);
//					}
//				}
//			}
//		}
//		return false;
//	}
//};

//优化上面的算法，如下：

class Solution {
	string target;
	int m;
	int n;
	bool findWord(vector<string> &board, int i, int j, int step, vector<vector<bool>> &used) {
		if (i < 0 || j < 0 || i >= m || j >= n || used[i][j]) {
			return false;
		}
		if (board[i][j] == target[step]) {
			used[i][j] = true;
			if (step == target.length() - 1) {
				return true;
			}
			if (findWord(board, i - 1, j, step + 1, used) ||
				findWord(board, i + 1, j, step + 1, used) ||
				findWord(board, i, j + 1, step + 1, used) ||
				findWord(board, i, j - 1, step + 1, used))
				return true;
			used[i][j] = false;
		}
		return false;
	}
public:
	bool exist(vector<string>& board, string word) {
		m = board.size();
		n = board[0].size();
		target = word;
		vector<vector<bool>> used;
		for (int i = 0; i < m; ++i) {
			vector<bool> row(n, false);
			used.push_back(row);
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (findWord(board, i, j, 0, used))
					return true;
			}
		}
		return false;
	}
};


void test() {
	/*
	["dgtjaljwlwsbdpqnjnlvrafrtmdrecekkxvliejwcdxfsosedfbxhgoastuzxylivgtgke","enibsarngxuhucpkckeyjbwwjucecojgdtjwtdlaafjwjzgojkmuojqzfughirnmkykfbx","hberxoqgcbsoxgznigjoprfefpdrweoegvvfjnlnqednmdcullkbepfkgidfnujvpgcyvo","lluoaitcffnpirhpdpyhunddkslmqgcdtytthpxmwkbeeitjatsuivasnlffujkpielpvi","drvexzpsirmbluwnpmburvfcmngxebghuborcfjkwvnjsmxhyydptirhyzfccnkwqansfz","edwsmqejxchcrcnlklkpppeblubbmicqlykypohosprmrgxbtjsiywkmslneupxfphfeyn","vqcocvuzznjtvjshvktkrpzowrvcvtrqktgoqaorpzllkdsgpnqgesubjsfglwzxrfojgc","bvdminrdvgqmnxejypbfvpduouacdieedjsozjrushghgmqgbslxhorvktyobeufontnym","hsvqzccqieiudrkwmvqmlrrfwhurwvdfnzxnbafjgnflgqhulxhwpadnjaffvkmklkxmme","yurdfzvmuimbgbdkomkvtfgfrrrpgftgznjgmhviphjwiogyasutzcbqvshdydjzsvggcb","priapspxqppmlqomhmgqpgtzgnuouwrjpblhtaelswydmmpvyxooehpmvjcrhtcyunfpom","agiylwncsnzgddpsrmbtdkmfjivqxjcarkycjlgdbflelcxcpayulkcwvxouirubdtfmgl","rhqcmdflgwleqyquuntjibccefxjuewlnnobqvmyraejyxevkxesbivfpurjanxocnrvie","vzeaiexozhofcpnxwdtpoudlkhabeihajlauszkrgyxinkhmpbbgxgrhouisequodukvvu","nctmmiywuozwuwendujlnodjejeoezktddfsmgoiwngqllfofrbuffejokzuljqppvjddz","lzmsrzdznkqqfvxjglvfigqyxfvgizfuytosstrhdhyicvtkjoptxfrulodvpipqefiyyz","icggmkdguowjhtqaodrtzgdqyhwgiwfqynylzbttqrezlxcbatuzbxsahogpkofldfydgt","wykdavacyavucysuybkfqwvxhyehdkacllflifphhmbjkvfjyrqqonpxntfrgftrqaezfv","iohlarjfchxsynfnktjpmpvhgnhmoohycokchvkkcjecwksgfbwtstaaihmxvvxzljcseo","ejxjntvfzcixvasxcbeoablxawhepnsvwpekkbrmdcjaeexhfdxhejehfnnwbgszxyjkad","wdfhelldsshqznbgugtkfusxupxfbxkxdphhdskvltnmhosdxmncifbexymywwyzmfirzu","mkocxvsrypdorotusqteprbpspuagtwugkwfhpwigcwaqpuigppxgsoahicpdzjjjiqtzp","bfrxhjoctwtitcahcjrfavekgpuzivolahkkqzmjvfurjuamgsrgpxsxmoyxjokmvvwluk","xrpriznlnvfecwdwvpluouizggwcrqmqjejsfxduukywgdvbsgvjagkjmgnfycwhifbneg","hzqhxwksyeavpdbzmnfbtfdrnlyoafvhenqdkcykjyfybjypwfrrlukaijqiqlswbizlnx","vwycublurkcidpeqrmbhxrvpnwzohmoeimifnwbgifqnwvdnjexgxsxkoxzxjndubnbqje","xtmnhikkywrveoncbdzcakrfesshieofxaveihridkdiasmbxldzvwecozlxdzeazbhkjy","umiywksimqvrptowxevidykiyjlfvufqjpqhakqoanfsgvodalodjynjjbrhvyxgopoozg","ectluchkhjvvogvephfioahnjvexlddpfwabajnisifhqblgkqoasvnbstadwduecvhcgv","mzfsiwtvednsfhqslillojpiptfxxosknxcxvxszchuhokbzuolixctpxamuoegddkabhu","albussgvrbjeljieyfhkcvqkzvvbwewzqztktagldrroaatahamjxeuyapaytyzlztwtvc","gytxowxhwfjjqjpkhrbhqxhpihkeahighefwaffykrjcazpjqqtipayajkgluprdvzzveh","tqadsachlsaebrfbrqnycjptnksohyvaovfhxhqjcqpfiuiblxzphqiwadkjdiksfpzdzp","odidksautnrvcalmworhxvpjnubozcfphntrfvlbkewmfhabxsixpzgcuhsvlxlsngjsbw","tnbrzibbjytuvkteoplglzeyrredlhzhucyvkbwwaqqxcjbrbpxmodkfwqiixkrrormbti","xtansdyuwzltnbxzgtprdmdwfroruhcrcegwjfsfgdbweyvntlgzxjvfclwxuaqyhxvqen","ymtzixzemurstqdrvieuhzuxxduuwaiunbvvawbpqshmlnfgxjaekxbiaycyamunpplsno","hejqsufzackdgvakfckjbkwvannlfcboikfaekbhpmkvhkhmorvretpejerogsdpdkphwt","qlfajmmqabkxuorjscnjqubvjghaqetgrahamvtoydmtrfclhswzmzxxgezwktecvleijx","whckavpdiyveyjevimbhkmcoqycwgluesyrvwiyehvjfgpcobdvlrybhydegqakjadewme","btbmajbcxehurzusgsymyomlznoflclmvmyxxbzufjrwinrqgpdgfrtfgkksmwekkfhigj","emsxkcldstsvbapvfvhrnvpufcbpmhyqvsqiudlmwgkzgbwnwdemzwigyjxmsxeopuwlxj","avpmvxnrkjxrxynfgnoezhbdxtavexeevwqstdlepixmimupzitarwfqphluhsacorujwf","nnqkaywupxeizyhhowocqxurzikvtibhwttyrsuhrartyycpvsrnqlgpvsnodoxzhtzanv","jgxbbwbdnyweomrudmpqcsgctpvsskpbqmeskgxxgtduhurnigdlymnrbkltuaxmobgbje","aqzemhadujjzwhljapvlkrnhdejmfuqfkrjzakcwvmwrvjcwaxjloxutbdfiaxnmpzlpjo","oeckvxvxvwwhjkedfhjlpjkcvzbhrmvfszrpymoukkbtwhxcqgpfrzjmbnvsbszurslqea","mrmnmjwjnmrctkdexerswtlxpepauwagnnvbytnlheparsfoxyivtvviaklwinfxcczawm","ndseejxlzwjktdfonhzygjmlhongrjsepmjvwigxerhxwnokwpkcywnfndleofkdutyqdg","nhavhwkxiimtlkraqeddkslvxfowxuembejkdthnetgpgaryexdrpomovcmswrfaxomaku","oopwfvwyvdvzumniblkndhgkjebvglpwbhvietiawezssoavznlfwrpfvqaedsagbxqfrz","hnfiizzkvyzgfvxvavndbtxdzybsfstnhavrzucuvbcazcxbzlgagddhbezhyuwgutzuob","qlftngxlhwyowetblvineghaoctoyjrowyjkegvoeveabxcoukdyslahpwxnfodeppotxl","jcgncjngxhsbinokudgtsohxuyoismtdobtsmibjrtmzgamcfuvzkfzednmxzhdpkwiwej","iveuxnxlrefnequfwzsjzuscjfatbeelbliayflpjrepjaufanqzjjdsodorjsdkdlldsw","vbpbtacniecyfljiezlurumwgsjrxbqsehuxkylscnqhzarfzezsynoghzafaszfzveltr","dxfwggyxnxbosbdiknikukctrdrwpmnsmuoscmspmvfgzjojwytqlxlcaeaprokdkaxnpp","edlklmvbvtaqjlnwpnbqfserxqrudikknxuyjragkawvnjrcyusdoyulroiwyugmtckctk","ifmgabpugnqytfzpssfcoewvspzcttpdydjbfyxlonljumyneervkoqcfpgzkvclbmoiml","tcaglvvmkbqbwcroexekwqiabjorrdcmfdutypfktxlpzdedakpyaxaeirvbuanbfiufzb","psyckzfochauharigczedverwlbtqcwhxvjjupxzyztgzmqiormumsnkfqfvsccrznatez","udyplacdiswwmkqzuvpcskewddjeyoftteiegmjohfmtpcvlzmnryrncuwitmnoftyjzls","nszbnofkaexpvvhkxdhfyvvmbonmoyhdsgfhxksxrrmmovxmzgtxbqmefzrtzywtedcbqw","ahnptcksqlallecxihyzczzaseeuhwridgzykltaxtokzsjkzhjdgldapjwyfpiiwhjivc","jsxzexrnhsusvcdaeukatrqdcollwgnhakigjztqrploropvlbxgupjwfwhcewlgjumsvf","lpuwdnmukzxkfszpoflyjswuyfqlamsldpjicxfpxczewatnfhnqzjlzpdkrrdeuundymi","njmoojpjywslntuatlfdcxigtcvydkiqvvhlgyveuppjjllcxrfboqkjuhixrqqnlzytxv","xtloduaqwzhdcxvohswprpfhetgdmfamznceheuffelibiwiauzukfboaktmpwaqjduthr","apvlxwwvhyqgscnwqnimczicqrhmkrdlgyyfxwagvsmpucnlpvztvhwnyfzlydyedwjcvm","iqexhzzvmqqlknsiaspafofdskcenxsxpwwyxvtlomwazqiclzcsnjwitaogxggoecmeai","pouoovgyxrzbknmivgijohruxvxlbxtrnpfdnldmfcqrpcbmijxxsotpmqanpwgennhazk","pgnfzehatsjqpdhkuvbwkssrxgeeifrxngcmmmmfexyvaffuairmbldatkgepxbdfgpsse","zybxtecaaejrrmfwmygucysgbzmstgwteaszevzebiyswdridxdivxqyyetskrnqrfpxcq","cebcyxhpimpnwkmmlkqeecxtspzjodcqhduiabzkqoxmblzmwpscupwmgxyvcanmfiuhlt","sbkrqldpzbgtdaibprapmdpbpwjldxevaqnqbshctqvwqgahxawlfnmujyfnvmkxezqgrz","kkpgjimlplnmwtziplgxydlidpitxbuimkoxscihnvvlqxtgicdihoqkfafdcalqmbpedx","nsujdliytqayykoqwtrcwvejnskcwnbjhvukicjdulbsvrjslcwjzctmudqqtrbaoylzaw","cvhgpdzavkctwdvrppuffpyisngfmjbqeiyvnywkkadgeyxvnudujbdbolgcujvastwhrs","sesvkwuishevcpyhrpszrnjondilkbdefwasuucmdgjhviooxjqqwbhlgrxsucxayxuttw","hwetebdsscbiuzlbnrsmlnoipphjkahtznmdopxgtbqocbppukdgzsqojyztyiozvbcjsc","smdicfmtxgdaocufsffrafzpfwqhgkjyyoiauwwtdzvtesayxfsylrnqofzwplwqzgsvdo","qiqmbwecubjmbwgoowvounbqdawvyzmojealaepwiajjxralnvbhiczndxldzxributdak","zilkukbuvorxxazwpewahvzbdavzfvjfgwpagrwehnbhpcffjbhqwhtajozpmkwuhlupes","tohwvzbagkcncauwagmbvymruveqmjiixsgsrhuxrykuzhsznedkfpbzmhqyqainsphjwe","iqcvmbeedrkgdpxgrlnjlejuteldpjhyzjvnnzrsscyvtxbkiotvufpqjctymcylntzass","skwshsrkebbyxvfonorgofknqygrabmvnknvchfhkghhemyrcryqwkfoioijpuecetzjaf","qnlxupjujnlhfjtlyczilqcruikurnzhamgweptnegwkqpvqtwygocxikkeezfnbuuzyls","nszlcrczhwxfenhcvtocznhpqblpbykqqjdscgtjeqqidxmbsafspmjfquxtshkjspduxx","fbpvmvuaymbdgsppyhlvbeenpweuscrxfjsrgoseavhjnyangmkjqoyfmczggtdmexfklz","oowvzkvzzblkmbamiprkvxfbljarvosjcpgbbdaafomtpniaezkzypakaddvrvgvkowlry","mymyuencerbqtzhvlhyoepkmkuciivjuwxuqbkuhdxxwyesknqytiifufjdnfojdlftppp","wtmwrkcjuscvlmftgmelbjzmmlshcjwyekwwvbhrtlogxuzgigrkprweeongamggwdctgm","nzxbfxxhdgnwqenmktdybfmilinqetcrububysidyxaqepcojhomoaualjqreuiyvccwwk","zukzkoppeayvmnxjpiufbzbjzyobumouhavtqmkumlpbypknzeubfvmfvaiqpymwyjrowe","lkpclnrvcrcwshteoohzgwxsuwcnmarxkgcwvttxkxvehqjvhsunquimqmzemreyzgwvzq","smpqqwgbspvoflinxabxfpqjnprkkqcfcrvvodwitsyydhndjoaqdsbshseslgxnauioxh","yqzwoefbhrrjhwdjpldvfoceccymsvvqmuocbwgknzwuwzfnmjirzmvdqtsirnafkrhlnp"]
	"cptynvechpk"
	*/
	vector<string> board = { "a" };
	string word = "b";
	Solution s;
	cout << s.exist(board, word);
}


