let s:cpo_save=&cpo
set cpo&vim
cnoremap <silent> <Plug>(TelescopeFuzzyCommandSearch) e "lua require('telescope.builtin').command_history { default_text = [=[" . escape(getcmdline(), '"') . "]=] }"
imap <C-G>S <Plug>ISurround
imap <C-G>s <Plug>Isurround
inoremap <M-l> l
inoremap <M-k> k
inoremap <M-j> j
inoremap <M-h> h
inoremap <C-W> u
inoremap <C-U> u
nnoremap  <Cmd>nohlsearch|diffupdate|normal! 
nmap  <Plug>(RepeatRedo)
tnoremap <expr>  '"'.nr2char(getchar()).'pi'
nmap  d
tnoremap  
nnoremap  j "+yy
vnoremap  s "+
nnoremap  s "+
vnoremap  k "_
nnoremap  k "_
nnoremap  tm :tabnew | term
omap <silent> % <Plug>(MatchitOperationForward)
xmap <silent> % <Plug>(MatchitVisualForward)
nmap <silent> % <Plug>(MatchitNormalForward)
nnoremap & :&&
xmap , <Plug>Sneak_,
omap , <Plug>Sneak_,
nmap , <Plug>Sneak_,
nmap . <Plug>(RepeatDot)
xmap ; <Plug>Sneak_;
omap ; <Plug>Sneak_;
nmap ; <Plug>Sneak_;
xnoremap <silent> @(targets) :call targets#do()
onoremap <silent> @(targets) :call targets#do()
xnoremap <silent> <expr> @ mode() ==# 'V' ? ':normal! @'.getcharstr().'' : '@'
xmap <expr> A targets#e('o', 'A', 'A')
omap <expr> A targets#e('o', 'A', 'A')
nnoremap F <Plug>Sneak_F
xmap <expr> I targets#e('o', 'I', 'I')
omap <expr> I targets#e('o', 'I', 'I')
xnoremap <silent> <expr> Q mode() ==# 'V' ? ':normal! @=reg_recorded()' : 'Q'
nmap S <Plug>Sneak_S
xmap S <Plug>VSurround
nnoremap T <Plug>Sneak_T
nmap U <Plug>(RepeatUndoLine)
nnoremap Y y$
xmap Z <Plug>Sneak_S
omap Z <Plug>Sneak_S
omap <silent> [% <Plug>(MatchitOperationMultiBackward)
xmap <silent> [% <Plug>(MatchitVisualMultiBackward)
nmap <silent> [% <Plug>(MatchitNormalMultiBackward)
nnoremap [d <Cmd>lua vim.diagnostic.goto_prev()
omap <silent> ]% <Plug>(MatchitOperationMultiForward)
xmap <silent> ]% <Plug>(MatchitVisualMultiForward)
nmap <silent> ]% <Plug>(MatchitNormalMultiForward)
nnoremap ]d <Cmd>lua vim.diagnostic.goto_next()
xmap a% <Plug>(MatchitVisualTextObject)
xmap <expr> a targets#e('o', 'a', 'a')
omap <expr> a targets#e('o', 'a', 'a')
nmap cS <Plug>CSurround
nmap cs <Plug>Csurround
nmap ds <Plug>Dsurround
nnoremap f <Plug>Sneak_f
nnoremap gl <Cmd>lua vim.diagnostic.open_float()
omap <silent> g% <Plug>(MatchitOperationBackward)
xmap <silent> g% <Plug>(MatchitVisualBackward)
nmap <silent> g% <Plug>(MatchitNormalBackward)
nmap gcu <Plug>Commentary<Plug>Commentary
xmap gr <Plug>ReplaceWithRegisterVisual
nmap gr <Plug>ReplaceWithRegisterOperator
xmap gS <Plug>VgSurround
tnoremap gT gT
tnoremap gt gt
nmap grr <Plug>ReplaceWithRegisterLine
omap gc <Plug>Commentary
nmap gcc <Plug>CommentaryLine
xmap gc <Plug>Commentary
nmap gc <Plug>Commentary
xmap <expr> i targets#e('o', 'i', 'i')
omap <expr> i targets#e('o', 'i', 'i')
tnoremap jk 
xmap s <Plug>Sneak_s
nmap s <Plug>Sneak_s
nnoremap t <Plug>Sneak_t
nmap u <Plug>(RepeatUndo)
nmap ySS <Plug>YSsurround
nmap ySs <Plug>YSsurround
nmap yss <Plug>Yssurround
nmap yS <Plug>YSurround
nmap ys <Plug>Ysurround
omap z <Plug>Sneak_s
nmap <C-R> <Plug>(RepeatRedo)
nnoremap <silent> <Plug>(RepeatDot) :if !repeat#run(v:count)|echoerr repeat#errmsg()|endif
xmap <silent> <Plug>(MatchitVisualTextObject) <Plug>(MatchitVisualMultiBackward)o<Plug>(MatchitVisualMultiForward)
onoremap <silent> <Plug>(MatchitOperationMultiForward) :call matchit#MultiMatch("W",  "o")
onoremap <silent> <Plug>(MatchitOperationMultiBackward) :call matchit#MultiMatch("bW", "o")
xnoremap <silent> <Plug>(MatchitVisualMultiForward) :call matchit#MultiMatch("W",  "n")m'gv``
xnoremap <silent> <Plug>(MatchitVisualMultiBackward) :call matchit#MultiMatch("bW", "n")m'gv``
nnoremap <silent> <Plug>(MatchitNormalMultiForward) :call matchit#MultiMatch("W",  "n")
nnoremap <silent> <Plug>(MatchitNormalMultiBackward) :call matchit#MultiMatch("bW", "n")
onoremap <silent> <Plug>(MatchitOperationBackward) :call matchit#Match_wrapper('',0,'o')
onoremap <silent> <Plug>(MatchitOperationForward) :call matchit#Match_wrapper('',1,'o')
xnoremap <silent> <Plug>(MatchitVisualBackward) :call matchit#Match_wrapper('',0,'v')m'gv``
xnoremap <silent> <Plug>(MatchitVisualForward) :call matchit#Match_wrapper('',1,'v'):if col("''") != col("$") | exe ":normal! m'" | endifgv``
nnoremap <silent> <Plug>(MatchitNormalBackward) :call matchit#Match_wrapper('',0,'n')
nnoremap <silent> <Plug>(MatchitNormalForward) :call matchit#Match_wrapper('',1,'n')
omap <Plug>SneakPrevious <Plug>Sneak_,
omap <Plug>SneakNext <Plug>Sneak_;
xmap <Plug>SneakPrevious <Plug>Sneak_,
xmap <Plug>SneakNext <Plug>Sneak_;
nmap <Plug>SneakPrevious <Plug>Sneak_,
nmap <Plug>SneakNext <Plug>Sneak_;
omap <Plug>(SneakStreakBackward) <Plug>SneakLabel_S
omap <Plug>(SneakStreak) <Plug>SneakLabel_s
xmap <Plug>(SneakStreakBackward) <Plug>SneakLabel_S
xmap <Plug>(SneakStreak) <Plug>SneakLabel_s
nmap <Plug>(SneakStreakBackward) <Plug>SneakLabel_S
nmap <Plug>(SneakStreak) <Plug>SneakLabel_s
xmap <Plug>VSneakPrevious <Plug>Sneak_,
xmap <Plug>VSneakNext <Plug>Sneak_;
xmap <Plug>VSneakBackward <Plug>Sneak_S
xmap <Plug>VSneakForward <Plug>Sneak_s
nmap <Plug>SneakBackward <Plug>Sneak_S
nmap <Plug>SneakForward <Plug>Sneak_s
onoremap <silent> <Plug>SneakLabel_S :call sneak#wrap(v:operator, 2, 1, 2, 2)
onoremap <silent> <Plug>SneakLabel_s :call sneak#wrap(v:operator, 2, 0, 2, 2)
xnoremap <silent> <Plug>SneakLabel_S :call sneak#wrap(visualmode(), 2, 1, 2, 2)
xnoremap <silent> <Plug>SneakLabel_s :call sneak#wrap(visualmode(), 2, 0, 2, 2)
nnoremap <silent> <Plug>SneakLabel_S :call sneak#wrap('', 2, 1, 2, 2)
nnoremap <silent> <Plug>SneakLabel_s :call sneak#wrap('', 2, 0, 2, 2)
onoremap <silent> <Plug>Sneak_T :call sneak#wrap(v:operator, 1, 1, 0, 0)
onoremap <silent> <Plug>Sneak_t :call sneak#wrap(v:operator, 1, 0, 0, 0)
xnoremap <silent> <Plug>Sneak_T :call sneak#wrap(visualmode(), 1, 1, 0, 0)
xnoremap <silent> <Plug>Sneak_t :call sneak#wrap(visualmode(), 1, 0, 0, 0)
nnoremap <silent> <Plug>Sneak_T :call sneak#wrap('', 1, 1, 0, 0)
nnoremap <silent> <Plug>Sneak_t :call sneak#wrap('', 1, 0, 0, 0)
onoremap <silent> <Plug>Sneak_F :call sneak#wrap(v:operator, 1, 1, 1, 0)
onoremap <silent> <Plug>Sneak_f :call sneak#wrap(v:operator, 1, 0, 1, 0)
xnoremap <silent> <Plug>Sneak_F :call sneak#wrap(visualmode(), 1, 1, 1, 0)
xnoremap <silent> <Plug>Sneak_f :call sneak#wrap(visualmode(), 1, 0, 1, 0)
nnoremap <silent> <Plug>Sneak_F :call sneak#wrap('', 1, 1, 1, 0)
nnoremap <silent> <Plug>Sneak_f :call sneak#wrap('', 1, 0, 1, 0)
onoremap <silent> <Plug>Sneak_, :call sneak#rpt(v:operator, 1)
onoremap <silent> <Plug>Sneak_; :call sneak#rpt(v:operator, 0)
xnoremap <silent> <Plug>Sneak_, :call sneak#rpt(visualmode(), 1)
xnoremap <silent> <Plug>Sneak_; :call sneak#rpt(visualmode(), 0)
nnoremap <silent> <Plug>Sneak_, :call sneak#rpt('', 1)
nnoremap <silent> <Plug>Sneak_; :call sneak#rpt('', 0)
onoremap <silent> <Plug>SneakRepeat :call sneak#wrap(v:operator, sneak#util#getc(), sneak#util#getc(), sneak#util#getc(), sneak#util#getc())
onoremap <silent> <Plug>Sneak_S :call sneak#wrap(v:operator, 2, 1, 2, 1)
onoremap <silent> <Plug>Sneak_s :call sneak#wrap(v:operator, 2, 0, 2, 1)
xnoremap <silent> <Plug>Sneak_S :call sneak#wrap(visualmode(), 2, 1, 2, 1)
xnoremap <silent> <Plug>Sneak_s :call sneak#wrap(visualmode(), 2, 0, 2, 1)
nnoremap <silent> <Plug>Sneak_S :call sneak#wrap('', 2, 1, 2, 1)
nnoremap <silent> <Plug>Sneak_s :call sneak#wrap('', 2, 0, 2, 1)
nmap <silent> <Plug>CommentaryUndo :echoerr "Change your <Plug>CommentaryUndo map to <Plug>Commentary<Plug>Commentary"
nnoremap <Plug>PlenaryTestFile :lua require('plenary.test_harness').test_file(vim.fn.expand("%:p"))
nnoremap <silent> <Plug>ReplaceWithRegisterVisual :call setline('.', getline('.'))|execute 'silent! call repeat#setreg("\<Plug>ReplaceWithRegisterVisual", v:register)'|call ReplaceWithRegister#SetRegister()|if ReplaceWithRegister#IsExprReg()|    let g:ReplaceWithRegister#expr = getreg('=')|endif|execute 'normal!' ReplaceWithRegister#VisualMode()|call ReplaceWithRegister#Operator('visual', "\<Plug>ReplaceWithRegisterVisual")
vnoremap <silent> <Plug>ReplaceWithRegisterVisual :call setline('.', getline('.'))|execute 'silent! call repeat#setreg("\<Plug>ReplaceWithRegisterVisual", v:register)'|call ReplaceWithRegister#SetRegister()|if ReplaceWithRegister#IsExprReg()|    let g:ReplaceWithRegister#expr = getreg('=')|endif|call ReplaceWithRegister#Operator('visual', "\<Plug>ReplaceWithRegisterVisual")
nnoremap <silent> <Plug>ReplaceWithRegisterLine :call setline('.', getline('.'))|execute 'silent! call repeat#setreg("\<Plug>ReplaceWithRegisterLine", v:register)'|call ReplaceWithRegister#SetRegister()|if ReplaceWithRegister#IsExprReg()|    let g:ReplaceWithRegister#expr = getreg('=')|endif|call ReplaceWithRegister#SetCount()|execute 'normal! V' . v:count1 . "_\<Esc>"|call ReplaceWithRegister#Operator('visual', "\<Plug>ReplaceWithRegisterLine", 1)
nnoremap <silent> <Plug>ReplaceWithRegisterExpressionSpecial :let g:ReplaceWithRegister#expr = getreg('=')|execute 'normal!' v:count1 . '.'
nnoremap <expr> <Plug>ReplaceWithRegisterOperator ReplaceWithRegister#OperatorExpression()
nnoremap <silent> <Plug>SurroundRepeat .
tnoremap <expr> <C-R> '"'.nr2char(getchar()).'pi'
tnoremap <M-l> l
tnoremap <M-k> k
tnoremap <M-j> j
tnoremap <M-h> h
nnoremap <M-l> l
nnoremap <M-k> k
nnoremap <M-j> j
nnoremap <M-h> h
nmap <C-W><C-D> d
nnoremap <C-L> <Cmd>nohlsearch|diffupdate|normal! 
imap S <Plug>ISurround
imap s <Plug>Isurround
inoremap  u
inoremap  u
inoremap jk 
let &cpo=s:cpo_save
unlet s:cpo_save
set expandtab
set grepformat=%f:%l:%c:%m
set grepprg=rg\ --vimgrep\ -uu\ 
set helplang=en
set ignorecase
set noloadplugins
set operatorfunc=<SNR>15_go
set packpath=/usr/share/nvim/runtime
set runtimepath=~/.config/nvim,~/.local/share/nvim/lazy/lazy.nvim,~/.local/share/nvim/lazy/LuaSnip,~/.local/share/nvim/lazy/vim-sneak,~/.local/share/nvim/lazy/targets.vim,~/.local/share/nvim/lazy/vim-fugitive,~/.local/share/nvim/lazy/nvim-lspconfig,~/.local/share/nvim/lazy/vim-repeat,~/.local/share/nvim/lazy/vim-commentary,~/.local/share/nvim/lazy/vim-indent-object,~/.local/share/nvim/lazy/nvim-treesitter,~/.local/share/nvim/lazy/cmp-nvim-lsp,~/.local/share/nvim/lazy/plenary.nvim,~/.local/share/nvim/lazy/telescope.nvim,~/.local/share/nvim/lazy/nvim-cmp,~/.local/share/nvim/lazy/typst.vim,~/.local/share/nvim/lazy/vim-ReplaceWithRegister,~/.local/share/nvim/lazy/mason.nvim,~/.local/share/nvim/lazy/mason-lspconfig.nvim,~/.local/share/nvim/lazy/vim-surround,~/.local/share/nvim/lazy/catppuccin,/usr/share/nvim/runtime,/usr/share/nvim/runtime/pack/dist/opt/matchit,/usr/lib64/nvim,~/.local/share/nvim/lazy/cmp-nvim-lsp/after,~/.local/share/nvim/lazy/catppuccin/after,~/.config/nvim/after,~/.local/state/nvim/lazy/readme
set shiftwidth=2
set showbreak=>>
set smartcase
set smartindent
set softtabstop=2
set spelllang=en_us
set tabstop=2
set termguicolors
set window=47
" vim: set ft=vim :
