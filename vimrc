

set number

set mouse=a

set list
set listchars=tab:>-,trail:-,extends:\#,nbsp:.

syntax on
filetype on
au BufNewFile,BufRead *.gex set filetype=gex

set hlsearch

nnoremap <CR> :noh<CR><CR>

set nowrap

inoremap jj <Esc>
nnoremap + :w<CR>a<Esc>

nnoremap K <Nop>


set tabstop=4
set shiftwidth=4
set softtabstop=4
"set expandtab
