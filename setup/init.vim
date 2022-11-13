syntax on
filetype plugin indent on
set ts=4 sts=4 sw=4 et ai si
set rnu
set nu
set mouse=a
setlocal spell
set spelllang=it,en_gb
inoremap <c-l> <c-g>u<Esc>[s1z=']a<c-g>u

call plug#begin()

Plug 'https://github.com/jiangmiao/auto-pairs'
Plug 'https://github.com/neoclide/coc.nvim'
Plug 'gruvbox-community/gruvbox'
Plug 'https://github.com/vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'preservim/nerdtree'
Plug 'https://github.com/lervag/vimtex'
Plug 'https://github.com/preservim/tagbar'
Plug 'SirVer/ultisnips'
Plug 'https://github.com/honza/vim-snippets'
Plug 'KeitaNakamura/tex-conceal.vim'

call plug#end()

" use <tab> for trigger completion and navigate to the next complete item
function! CheckBackspace() abort
  let col = col('.') - 1
  return !col || getline('.')[col - 1]  =~# '\s'
endfunction

inoremap <expr> <cr> coc#pum#visible() ? coc#pum#confirm() : "\<CR>"

inoremap <silent><expr> <Tab>
      \ coc#pum#visible() ? coc#pum#next(1) :
      \ CheckBackspace() ? "\<Tab>" :
      \ coc#refresh()

set termguicolors
colo gruvbox

inoremap <c-t> <Esc>:NERDTreeToggle<cr>
nnoremap <c-t> <Esc>:NERDTreeToggle<cr>

nmap <c-v> :VimtexCompile<CR>

map <F8> :w <CR> :!gcc % -o %< -lm && ./%< <CR>

nmap <c-b> :TagbarToggle<CR>

let g:tex_flavor='latex'
let g:vimtex_view_method='zathura'
let g:vimtex_quickfix_mode=0
set conceallevel=1
let g:tex_conceal='abdmg'
hi Conceal ctermbg=none

let g:UltiSnipsEditSplit="vertical"
let g:UltiSnipsExpandTrigger = '<tab>'
let g:UltiSnipsJumpForwardTrigger = '<tab>'
let g:UltiSnipsJumpBackwardTrigger = '<s-tab>'
let g:UltiSnipsSnippetsDir = "~/.local/share/nvim/plugged/ultisnips"

