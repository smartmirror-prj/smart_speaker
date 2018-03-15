"-------------------------------------------------------------"
" vim 환경설정
"-------------------------------------------------------------"

syntax on
set nu                        "라인 줄 표시"
set cindent                   "C언어 자동 들여쓰기"
set ai
set ts=4                      "tab size"
set bg=dark                   "background color"
set hls                       "검색어 하이라이트 강조"
set autoindent			      "자동 들여쓰기
set smartindent				  "스마트한 들여쓰기
set shiftwidth=4			  "자동 들여쓰기할 때 여백
set showmatch   			  "괄호를 맞춰줌
set laststatus=2 			  " 상태바 표시를 항상한다
set statusline=\ %<%l:%v\ [%P]%=%a\ %h%m%r\ %F\
set expandtab 				  " 탭을 사용하면 공백으로 변환



"-------------------------------------------------------------"
" ctags database path 설정
" ctags DB 위치 <home/code> 자신의 경로로 변경
"-------------------------------------------------------------"

set tags=/usr/src/linux/tags,/home/venture/testSrc/pca9685_app/tags



"-------------------------------------------------------------"
" cscope database 설정
"-------------------------------------------------------------"

set csprg=/usr/bin/cscope          "cscope 위치
set csto=0                         "cscope DB search first
set cst                            "cscope DB tag DB search
set nocsverb                       "verbose off



"cscope DB의 위치 설정, <home/code> 변경, 절대경로 사용 
cs add /usr/src/linux/cscope.out    /usr/src/linux
set csverb                         "verbose off

"-------------------------------------------------------------"
" Tag List 환경설정
"-------------------------------------------------------------"

filetype on                           "vim filetype on
nmap <F7> :TlistToggle<CR>

let Tlist_Ctags_Cmd = "/usr/bin/ctags"
let Tlist_Inc_Winwidth = 0
let Tlist_Exit_OnlyWindow = 0
let Tlist_Auto_Open = 0
let Tlist_Use_Right_Window = 1



"-------------------------------------------------------------"
" Source Explorer 환경설정
"-------------------------------------------------------------"

nmap <F8> :SrcExplToggle<CR>
nmap <C-H> <C-W>h
nmap <C-J> <C-W>j
nmap <C-K> <C-W>k
nmap <C-L> <C-W>l



let g:SrcExpl_winHeight = 8
let g:SrcExpl_refreshTime = 100
let g:SrcExpl_jumpKey = "<Enter>"
let g:SrcExpl_gobackKey = "<SPACE>"
let g:SrcExpl_isUpdateTags = 0



"-------------------------------------------------------------"
" NERD Tree 환경설정
"-------------------------------------------------------------"

let NERDTreeWinPos = "left"
nmap <F9> :NERDTreeToggle<CR>



"-------------------------------------------------------------"

map <F5> :w<cr> :make<cr> :cc<cr> :cw<cr>

